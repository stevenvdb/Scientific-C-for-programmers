#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef USE_BLAS
#include <cblas.h>
#endif

#include "include/mnist_file.h"
#include "include/neural_network.h"

// Convert a pixel value from 0-255 to one from 0 to 1
#define PIXEL_SCALE(x) (((float) (x)) / 255.0f)

// Returns a random value between 0 and 1
#define RAND_FLOAT() (((float) rand()) / ((float) RAND_MAX))

/**
 * Initialise the weights and bias vectors with values between 0 and 1
 */
void neural_network_random_weights(neural_network_t * network)
{
    int i, j;

    for (i = 0; i < MNIST_LABELS; i++) {
        network->b[i] = RAND_FLOAT();

        for (j = 0; j < MNIST_IMAGE_SIZE; j++) {
            network->W[i][j] = RAND_FLOAT();
        }
    }
}

/**
 * Calculate the softmax vector from the activations. This uses a more
 * numerically stable algorithm that normalises the activations to prevent
 * large exponents.
 */
void neural_network_softmax(float * activations, int length)
{
    int i;
    float sum, max;

    for (i = 1, max = activations[0]; i < length; i++) {
        if (activations[i] > max) {
            max = activations[i];
        }
    }

    for (i = 0, sum = 0; i < length; i++) {
        activations[i] = exp(activations[i] - max);
        sum += activations[i];
    }

    for (i = 0; i < length; i++) {
        activations[i] /= sum;
    }
}

/**
 * Use the weights and bias vector to forward propogate through the neural
 * network and calculate the activations.
 */
void neural_network_hypothesis(mnist_image_t * image, neural_network_t * network, float activations[MNIST_LABELS])
{
#ifdef USE_BLAS
    // Store scaled pixels
    float x[MNIST_IMAGE_SIZE];
    for (int j = 0; j < MNIST_IMAGE_SIZE; j++) {
        x[j] = PIXEL_SCALE(image->pixels[j]);
    }
    // Copy bias into activation, which BLAS will use as output
    for (int i = 0; i < MNIST_LABELS; i++) {
        activations[i] = network->b[i];
    }

    cblas_sgemv(CblasRowMajor, CblasNoTrans, MNIST_LABELS, MNIST_IMAGE_SIZE,
                1.0f, &network->W[0][0], MNIST_IMAGE_SIZE, x, 1, 1.0f, activations, 1);
#else
    int i, j;

    for (i = 0; i < MNIST_LABELS; i++) {
        activations[i] = network->b[i];

        for (j = 0; j < MNIST_IMAGE_SIZE; j++) {
            activations[i] += network->W[i][j] * PIXEL_SCALE(image->pixels[j]);
        }
    }
#endif

    neural_network_softmax(activations, MNIST_LABELS);
}

/**
 * Update the gradients for this step of gradient descent using the gradient
 * contributions from a single training example (image).
 * 
 * This function returns the loss ontribution from this training example.
 */
float neural_network_gradient_update(mnist_image_t * image, neural_network_t * network, neural_network_gradient_t * gradient, uint8_t label)
{
    float activations[MNIST_LABELS];

    // First forward propagate through the network to calculate activations
    neural_network_hypothesis(image, network, activations);

#ifdef USE_BLAS
    // Compute b_grad vector
    float b_grad[MNIST_LABELS];
    for (int i = 0; i < MNIST_LABELS; i++) {
        b_grad[i] = activations[i] - ((i == label) ? 1.0f : 0.0f);
        gradient->b_grad[i] += b_grad[i];
    }

    // Compute scaled input vector x
    float x[MNIST_IMAGE_SIZE];
    for (int j = 0; j < MNIST_IMAGE_SIZE; j++) {
        x[j] = PIXEL_SCALE(image->pixels[j]);
    }


    // Update W_grad using BLAS SGER (rank-1 update)
    // W_grad += b_grad * x^T
    cblas_sger(CblasRowMajor, MNIST_LABELS, MNIST_IMAGE_SIZE,
               1.0f, b_grad, 1, x, 1, &gradient->W_grad[0][0], MNIST_IMAGE_SIZE);
#else
    int i, j;
    float W_grad, b_grad;
    for (i = 0; i < MNIST_LABELS; i++) {
        // This is the gradient for a softmax bias input
        b_grad = (i == label) ? activations[i] - 1 : activations[i];

        for (j = 0; j < MNIST_IMAGE_SIZE; j++) {
            // The gradient for the neuron weight is the bias multiplied by the input weight
            W_grad = b_grad * PIXEL_SCALE(image->pixels[j]);

            // Update the weight gradient
            gradient->W_grad[i][j] += W_grad;
        }

        // Update the bias gradient
        gradient->b_grad[i] += b_grad;
    }
#endif

    // Cross entropy loss
    return 0.0f - log(activations[label]);
}

/**
 * Run one step of gradient descent and update the neural network.
 */
float neural_network_training_step(mnist_dataset_t * dataset, neural_network_t * network, float learning_rate)
{
    neural_network_gradient_t gradient;
    float total_loss;
    int i, j;

    // Zero initialise gradient for weights and bias vector
    memset(&gradient, 0, sizeof(neural_network_gradient_t));

    // Calculate the gradient and the loss by looping through the training set
    for (i = 0, total_loss = 0; i < dataset->size; i++) {
        total_loss += neural_network_gradient_update(&dataset->images[i], network, &gradient, dataset->labels[i]);
    }

    // Apply gradient descent to the network
    for (i = 0; i < MNIST_LABELS; i++) {
        network->b[i] -= learning_rate * gradient.b_grad[i] / ((float) dataset->size);

        for (j = 0; j < MNIST_IMAGE_SIZE; j++) {
            network->W[i][j] -= learning_rate * gradient.W_grad[i][j] / ((float) dataset->size);
        }
    }

    return total_loss;
}
