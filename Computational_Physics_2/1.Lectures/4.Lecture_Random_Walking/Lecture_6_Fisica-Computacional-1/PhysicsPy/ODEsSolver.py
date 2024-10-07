"""
Luis Eduardo Sánchez González

Universidad Autonoma de Coahuila
Facultad de Ciencias Físico Matemáticas

mié 03 feb 2021 13:10:46 CST 
"""
import numpy as np

class ODESolve():

	def __init__(self, f, System = True):

		self.f, self.System = f, System

	def __str__(self):

		return f"""
			Condition initial is: {self.U0}
			Time points is: {self.N}
			Number equations is: {self.NumEqns}  
			Number coordinates is: {self.NumCoor}
			"""

	def InitialConditions(self, U0, Deltat, dt):
	
		self.N = int((Deltat[1]-Deltat[0])/dt)
		self.t = np.linspace(Deltat[0], Deltat[1], self.N +1)

		if isinstance(U0, (int, float)):
	
			self.NumEqns, self.NumCoor = 1, 1
			U0 = float(U0)

		else:
	
			self.NumEqns = len(U0)
				
			if isinstance(U0[0], np.ndarray) or self.System == False:

				try: 

					self.NumCoor = len(U0[0])
					
					U = []	
					
					for i in range(self.NumEqns):
					
						U.append(U0[i])
					
					U0 = np.concatenate(tuple(U))

				except:
			
					self.NumCoor = 1
					U0 = np.asarray(U0)

			else:

				self.NumCoor = 1
				U0 = np.asarray(U0)

		self.U0 = U0

	def SolveODE(self):

		self.U = np.zeros((len(self.t), (self.NumCoor)*(self.NumEqns)))
			 
		self.U[0,:] = self.U0 

		#Integration	
		for i in range(self.N):
			self.i = i 
			self.U[i + 1] = self.advance()

		return self.U, self.t
