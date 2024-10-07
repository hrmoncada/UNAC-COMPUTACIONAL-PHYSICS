"""
Luis Eduardo Sánchez González

Universidad Autonoma de Coahuila
Facultad de Ciencias Físico Matemáticas

jue 27 may 2021 17:24:20  
"""
import numpy as np
import matplotlib.pyplot as plt
from Molecular_Dynamics import Molecular_Dynamics


if __name__ == "__main__":

	import matplotlib.animation as animation
	
	Box = Molecular_Dynamics(64, 10, 5, 1, 0.01)
	Box.initial_conditions()
	
	plt.style.use("seaborn")
	plt.scatter(Box.X[:,0], Box.X[:,1], marker = "o")
	plt.show()
