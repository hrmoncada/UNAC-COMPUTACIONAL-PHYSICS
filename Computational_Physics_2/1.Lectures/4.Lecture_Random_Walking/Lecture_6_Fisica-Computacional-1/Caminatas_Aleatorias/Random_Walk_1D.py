"""
Caminata aleatoria unidimensional (Manera simple)
Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
https://github.com/Luis2501/Fisica-Computacional-1.git
"""
import numpy as np 

def Random_Walk(N, p):

	X = np.random.random(N)				    #Arreglo de números aleatorios entre 0 y 1
	steps = np.where((X<p) == True, 1, -1)	#Arreglo condicionado (x<p), p es la probabilidad 
	new_steps = np.zeros(N)				    #Arreglo de la posición

	for i in range(len(new_steps)-1):

		new_steps[i + 1] = sum(steps[:i +1])

	return new_steps

if __name__=="__main__":

	import matplotlib.pyplot as plt

	x = Random_Walk(20, 0.5)

	plt.title("Caminata aleatoria unidimensional")
	plt.plot(x) ; plt.grid()
	plt.xlabel("tiempo (s)") ; plt.ylabel("Posición (Pasos)")	
	plt.show()	
