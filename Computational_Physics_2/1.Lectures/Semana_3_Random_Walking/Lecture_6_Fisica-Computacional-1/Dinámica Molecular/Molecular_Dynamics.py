"""
Clase para simulación de dinámica molecular en 2D (Potencial de Lennard-Jones) 
NOTA: No terminada

Luis Eduardo Sánchez González

Universidad Autonoma de Coahuila
Facultad de Ciencias Físico Matemáticas

jue 27 may 2021 17:24:20  
"""
import numpy as np 

class Molecular_Dynamics: 

	def __init__(self, N, L, v, sigma, temp):
	
		self.N, self.L, self.v = N, L, v
		self.sigma, self.temp = sigma, temp
		
	def initial_conditions(self):	
	
		r = 0.01
		n = int(np.ceil(np.sqrt(self.N)))
		nf = 1.0/float(n)

		celdas = [[i*nf + 0.5*nf + r*np.random.rand(), 
			   j*nf + 0.5*nf + r*np.random.rand()] 
			   for i in range(n) for j in range(n)]		

		np.random.shuffle(celdas)   

		self.X = np.array(celdas)*self.L - self.L/2
			
		self.V = np.random.rand(self.N,2)-0.5*np.ones((self.N,2))
    
		Vx = sum(self.V[:,0])/self.N
		Vy = sum(self.V[:,1])/self.N
    
		#Calculamos la velocidad cuadratica media
		V2 = sum(sum(self.V**2))/self.N
    
    		#Factor de escala para temperatura
		fs = np.sqrt(2*self.temp/V2)
    
		#Elimino la velocidad del centro de masa y escalo
		self.V[:,0] = (self.V[:,0] - Vx)*fs
		self.V[:,1] = (self.V[:,1] - Vy)*fs
		
		self.X = (self.X*self.L)/self.sigma 

	def boundary_conditions(self):
	
		pass

