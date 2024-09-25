"""
Condiciones de contorno

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional 

dom 23 may 2021 12:41:15

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import numpy as np 

class Box:

	def __init__(self, L):
	
		self.L = L
		
	def position(self, s):
	
		if s > self.L:
		
			s -= self.L
			
		elif s<0:
		
			s+= self.L
			
		return s
		
	def new_position(self, s):
	
		return s%(2*self.L) if s <0 else s%self.L
		
if __name__ == "__main__":

	from timeit import default_timer
	
	box = Box(1)						#Caja de 1x1
	
	x = -2 + (4)*np.random.random(100000) 			#Números aleatorios entre [-2,2]
	
	R, T = [], []				
	
	for s in x:
	
		Inicio = default_timer()
		box.position(s)
		Fin = Inicio - default_timer()			#Tiempo que tarda la condición tradicional
	
		Inicio1 = default_timer()
		box.new_position(s)
		Fin1 = Inicio - default_timer()			#Tiempo que tarda la condición con el operador %
		
		if Fin1 < Fin:		
		
			R.append(True)	
			T.append(Fin - Fin1)	
			
	print(f"El operador % fue más rapido {len(R)} veces de {len(x)} veces")
	print(f"En promedio la diferencia de tiempo fue {np.mean(T)} segundos")
