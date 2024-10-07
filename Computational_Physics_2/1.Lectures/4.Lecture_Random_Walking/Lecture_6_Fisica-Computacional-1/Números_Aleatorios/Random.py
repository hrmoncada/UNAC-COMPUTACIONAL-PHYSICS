"""
Clase "Generador números aleatorios" 

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional

sáb 08 may 2021 13:11:11 CDT 

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import numpy as np

class Random_Number:

	def __init__(self, r0, a, c, m):

		self.r0, self.a, self.c, self.m = r0, a, c, m

	def random(self, A = 0, B = 1, size = 1):

		r0, a, c, m = self.r0, self.a, self.c, self.m 
	
		if isinstance(size, (int, float)):
	
			if size == 1:

				self.r0 = ((a*r0 + c)%m)		

				return self.r0/m

			else: 
		
				self.r = np.zeros(size)

				for i in range(size):

					r0 = ((a*r0 + c)%m)
					self.r[i] = r0 					

				return self.r/m

		elif isinstance(size, (tuple, list)):

			self.r = np.zeros(size)
							
			for k in range(size[0]):

				for i in range(size[1]):

					r0 = (a*r0 + c)%m
					self.r[k][i] = r0

			return self.r/m
