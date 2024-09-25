"""
Caminata aleatoria unidimensional (Manera tradicional)

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional 

mar 13 abr 2021 15:56:19 CDT 

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import numpy as np 

def Random_Walk(N, p):

	X = np.random.random(N)				#Arreglo de números aleatorios entre 0 y 1
	steps = np.zeros(N)				#Arreglo de la posición

	for i in range(len(steps)-1):

		if X[i] < 0.5:

			steps[i + 1] = steps[i] + 1

		else: 

			steps[i + 1] = steps[i] - 1

	return steps

if __name__=="__main__":

	import matplotlib.pyplot as plt

	x = Random_Walk(20, 0.5)

	plt.title("Caminata aleatoria unidimensional")
	plt.plot(x) ; plt.grid()
	plt.xlabel("tiempo (s)") ; plt.ylabel("Posición (Pasos)")	
	plt.show()
