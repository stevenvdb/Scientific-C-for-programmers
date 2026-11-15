.PHONY: all run clean

all:
	python setup.py build_ext -i

run: all
	python mandelbrot.py

clean:
	rm -rf build __pycache__ *.so _cmandelbrot.c mandelbrot_c.png
