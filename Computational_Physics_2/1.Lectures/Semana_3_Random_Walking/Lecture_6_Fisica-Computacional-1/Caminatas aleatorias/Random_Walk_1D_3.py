"""
Caminata aleatoria unidimensional (Promedios estadísticos)

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional 

jue 15 abr 2021 09:55:53 CDT  

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import numpy as np 

def Random_Walk(N, p):

	X = np.random.random(N)					#Arreglo de números aleatorios entre 0 y 1
	steps = np.where((X<p) == True, 1, -1)			#Arreglo condicionado (x<p), p es la probabilidad 
	new_steps = np.zeros(N)					#Arreglo de la posición

	for i in range(len(new_steps)-1):

		new_steps[i + 1] = sum(steps[:i +1])

	return new_steps

if __name__=="__main__":

	import matplotlib.pyplot as plt

	distances = np.zeros(100)				#Arreglo para almacenar las distancias

	for i in range(len(distances)):

		x = Random_Walk(20, 0.5)			#Hacemos la caminata aleatoria

		steps = np.where(x<0, abs(x), x)		#Donde la distancia es negativa, lo intercambiamos por su valor absoluto
		distances[i] = steps[-1]			#Buscamos la distancia después de 20 pasos

		if i % 10 == 0:

			plt.plot(x, label = f"{i}")

	print("Distancia promedio recorrida: ", np.mean(distances), " pasos")		#Promediamos las distancias

	plt.title("Caminatas aleatorias")
	plt.xlabel("tiempo (s)") ; plt.ylabel("Posición (Pasos)")
	plt.legend() ; plt.grid()	
	plt.show()	
