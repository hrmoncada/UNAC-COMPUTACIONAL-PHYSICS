'''
https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/ 
C++ program for estimation of Pi using Monte Carlo Simulation 
'''
import random

INTERVAL = 1000

circle_points = 0
square_points = 0

# Total Random numbers generated= possible x
# values* possible y values
for i in range(INTERVAL**2):

	# Randomly generated x and y values from a
	# uniform distribution
	# Range of x and y values is -1 to 1
	rand_x = random.uniform(-1, 1)
	rand_y = random.uniform(-1, 1)

	# Distance between (x, y) from the origin
	origin_dist = rand_x**2 + rand_y**2

	# Checking if (x, y) lies inside the circle
	if origin_dist <= 1:
		circle_points += 1

	square_points += 1

	# Estimating value of pi,
	# pi= 4*(no. of points generated inside the
	# circle)/ (no. of points generated inside the square)
	pi = 4 * circle_points / square_points

## print(rand_x, rand_y, circle_points, square_points, "-", pi)
# print("\n")

print("Final Estimation of Pi=", pi)

