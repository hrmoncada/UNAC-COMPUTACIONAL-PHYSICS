"""
Luis Eduardo Sánchez González

Universidad Autonoma de Coahuila
Facultad de Ciencias Físico Matemáticas

mié 03 feb 2021 13:10:46 CST 
"""
import numpy as np

class Difference: 

	def __init__(self, f):

		if callable(f):

			self.f = f

		else: 

			raise ValueError("La derivada es igual a cero.")

	def InitialConditions(self, x0, h):

		if isinstance(x0, (int, float)):

			self.x0 = x0

		else:
		
			self.x0 = np.asarray(x0)

		self.h = h

class Forward(Difference):

	def Solve(self):

		f, x0, h = self.f, self.x0, self.h

		return (f(x0 + h) - f(x0))/h		

class Central(Difference):

	def Solve(self):

		f, x0, h = self.f, self.x0, self.h

		return (f(x0 + h) - f(x0 - h))/(2*h)
		
class Backward(Difference):

	def Solve(self):

		f, x0, h = self.f, self.x0, self.h

		return (f(x0) - f(x0 - h))/h 
