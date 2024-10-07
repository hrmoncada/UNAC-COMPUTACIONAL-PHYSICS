'''
https://kamemori.com/python/quick_introduction/lesson05.html
'''
import random

# Number of random points to use for the Monte Carlo simulation
n = 10000

# Function to integrate
def f(x):
    return 4.0/(1.0 + x**2)

# Monte Carlo integration
integral = 0.0

for _ in range(n):
    integral = integral + f(random.random())

integral = integral / n

print('integral =',integral)
