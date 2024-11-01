# https://www.geeksforgeeks.org/estimating-pi-with-buffons-needle-in-python/
import random
import math

def buffon_needle_pi(num_trials, needle_length, line_spacing):
    crossings = 0
    for _ in range(num_trials):
        angle_degrees = random.uniform(0, 90)  # Random angle in degrees [0, 90]
        angle_radians = math.radians(angle_degrees)  # Convert angle to radians
        distance = random.uniform(0, line_spacing / 2)  # Random distance from the center of the needle to the nearest line
        if distance <= (needle_length / 2) * math.sin(angle_radians):  # Check if the needle crosses a line
            crossings += 1
    if crossings == 0:  # Avoid division by zero
        return None
    return (2 * needle_length * num_trials) / (crossings * line_spacing)  # Estimate Pi

# Estimate Pi using 1,000,000 trials, needle length 1.0, and line spacing 1.0
pi_estimate = buffon_needle_pi(1000000, 1.0, 1.0)
print("Buffon's Needle Pi Estimate:", pi_estimate)

# Original value of Pi for comparison
print("Original value of Pi:", math.pi)

