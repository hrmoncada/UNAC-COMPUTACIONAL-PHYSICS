"""
https://notmatthancock.github.io/2017/02/10/calling-fortran-from-python.html
"""

import numpy as np
import matplotlib.pyplot as plt
import sys   
import my_lib as ml

# Read matrix from text file as double precision matrix.
I = np.genfromtxt('./image.txt', dtype=np.float64)

# Threshold value.
t = 0.3

# Call the fortran routine.
T = ml.threshold_image(image=I, threshold=t)

# Plot the images.
fig, axes = plt.subplots(1, 2)

axes[0].imshow(I, cmap=plt.cm.gray)
axes[0].axis('off'); axes[0].set_title('Original')

axes[1].imshow(T, cmap=plt.cm.gray)
axes[1].axis('off'); axes[1].set_title('Thresholded at %.2f' % t)

plt.tight_layout()
plt.show()
