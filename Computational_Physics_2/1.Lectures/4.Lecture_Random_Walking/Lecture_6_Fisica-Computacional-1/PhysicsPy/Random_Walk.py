"""
Caminatas aleatorias (Crear distintos tipos de caminatas) 

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional 

jue 15 abr 2021 09:55:53 CDT  

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import numpy as np 
import random as rn

class Random_Walk:

	def __init__(self, p, N):

		if p >= 0 and p <= 1:
		
			self.p, self.N = p, N

		else: 

			raise ValueError("Probability out of range")

	def Multiple_Walkers(self, M):

		self.M = M	
		
		if isinstance(self, Random_Walk_1D):

			self.Steps = np.zeros((self.N, self.M)) 

			for i in range(self.M):

				self.Steps[:,i] = self.Walk()
	
		elif isinstance(self, Random_Walk_2D): 	

			self.Steps = np.zeros((self.N, 2*(self.M))) 

			for i in range(self.M):

				self.Steps[:,i], self.Steps[:,i+1] = self.Walk()		

		elif isinstance(self, Random_Walk_Avoiding):

			self.Steps = np.zeros(((self.N + 1), 2*(self.M))) 

			for i in range(self.M):

				self.Steps[:,i], self.Steps[:,i+1] = self.Walk()			

		return self.Steps
				
	def Mean_Distances(self, cuadratic = False):

		r = np.zeros(self.N)

		if isinstance(self, Random_Walk_1D):

			for i in range(self.M):

				r += (1/self.M)*(self.Steps[:,i]**2)

		elif isinstance(self, Random_Walk_2D):

			if cuadratic:

				for i in range(self.M):

					r += (1/self.M)*(self.Steps[:,i]**2 + self.Steps[:,i+1]**2)

			else:

				for i in range(self.M):

					r += (1/self.M)*np.sqrt(self.Steps[:,i]**2 + self.Steps[:,i+1]**2)

		return r
	
class Random_Walk_1D(Random_Walk):	

	def Walk(self):

		N, p = self.N, self.p

		X = np.random.random(N)					
		self.steps = np.cumsum(np.where((X<=p) == True, 1, -1))

		return self.steps		 

class Random_Walk_2D(Random_Walk):

	def Walk(self):
	
		N, p = self.N, self.p

		X = np.random.random(N)
		Y = np.random.random(N)	
				
		self.steps_x = np.cumsum(np.where((X<=p) == True, 1, -1))
		self.steps_y = np.cumsum(np.where((Y<=p) == True, 1, -1))

		return self.steps_x, self.steps_y

class Random_Walk_Avoiding(Random_Walk):

	def Walk(self):

		N, p = self.N, self.p 

		x = np.zeros(N+1)
		y = np.zeros(N+1)
		X, Y, i =0, 0, 0

		count = 0
		
		while(i < N):
			
			i+=1
  
			r = rn.random()

			if r<0.25:

				X-=1

			if 0.25<r<0.5:
		
				X+=1

			if 0.5<r<0.75:

				Y+=1

			if 0.75<r<1:

				Y-=1

			x[i]=X
			y[i]=Y

			for k in range(i):

				if x[k]==x[i] and y[k]==y[i]:
				
					X,Y, i = 0,0,0
			count += 1			
				
		return x, y, count
