'''
https://kamemori.com/python/quick_introduction/lesson05.html
'''
import matplotlib.pyplot as plt
import random

# Number of random points to generate
n = 10000

# Initializing counters for points inside and outside the circle
num_inside_circle = 0
num_outside_circle = 0

# Lists for storing points for plotting
x_inside = []
y_inside = []
x_outside = []
y_outside = []

# Generating random points and calculating Pi
for _ in range(n):
    x, y = random.random(), random.random()
    distance = x**2 + y**2

    if distance <= 1:
        num_inside_circle += 1
        x_inside.append(x)
        y_inside.append(y)
    else:
        num_outside_circle += 1
        x_outside.append(x)
        y_outside.append(y)

# Estimating Pi
pi_estimate = 4 * num_inside_circle / n

# Plotting the points
plt.figure(figsize=(6,6))
plt.scatter(x_inside, y_inside, color='blue', s=1)
plt.scatter(x_outside, y_outside, color='red', s=1)
plt.title(f'Estimation of Pi using Monte Carlo Method: {pi_estimate}')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.savefig('pi_mc.png')
plt.show()

