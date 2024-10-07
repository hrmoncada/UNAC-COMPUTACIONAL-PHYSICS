"""
Método de Verlet adaptado para dinámica molecular 

Luis Eduardo Sánchez González

Universidad Autonoma de Coahuila
Facultad de Ciencias Físico Matemáticas

jue 27 may 2021 17:24:20  
"""
import numpy as np
from Molecular_Dynamics import Molecular_Dynamics

class Velocity_Verlet(Molecular_Dynamics):

	def advance(self):

		u, f, i, t = self.U, self.f, self.i, self.t
		dt, k = t[i + 1] - t[i], self.NumCoor

		if k==1:

			x1 = 2*u[i,0] - u[i-1,0] + (f(u[i,:], t[i])[1])*(dt**2)
			x2 = (x1 - u[i,0])/(2*dt)
				
			return np.array([x1,x2])
				
		else:
			
			x1 = u[i,:k] +  + (0.5)*(f(u[i, :], t[i])[:k])*(dt**2) 
			x2 = np.zeros(k)
					
			return np.concatenate((x1, x2))
