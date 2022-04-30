import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pyplot import cm

mymatrix = np.loadtxt('pixel_data.txt')

plt.imsave('mandelbrot.jpeg', mymatrix, cmap=cm.gray)