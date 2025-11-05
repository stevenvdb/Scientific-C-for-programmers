import matplotlib.pyplot as plt
import numpy as np
from glob import glob

from matplotlib.animation import FuncAnimation, PillowWriter

Nx = 64
Ny = 64
#fn = 'u_%08d.bin' % 2040000
#print(fn)
fns = sorted(glob('u*.bin'))


fig, ax = plt.subplots()
u = np.fromfile(fns[0], dtype=np.float64).reshape((Nx, Ny))
im = ax.imshow(u, cmap='hot', interpolation='nearest')

def update(frame):
    u = np.fromfile(fns[frame], dtype=np.float64).reshape((Nx, Ny))
    im.set_array(u)
    return [im]

ani = FuncAnimation(fig, update, frames=len(fns), blit=True)

# Save as GIF
ani.save("heat_diffusion.gif", writer=PillowWriter(fps=30))

