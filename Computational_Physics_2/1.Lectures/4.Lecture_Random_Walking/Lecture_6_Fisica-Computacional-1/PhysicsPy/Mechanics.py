"""
Movimiento rectilineo uniforme 

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional

lun 22 feb 2021 13:03:42 CST 
"""
import numpy as np 

class MRU:

	def __init__(self, v):

		self.v = v

	def __call__(self, u, t):

		x, v = u, self.v

		return v

class MRUA:

	def __init__(self, g):

		self.g = g

	def __call__(self, u, t):

		v, g = u, self.g 

		return -g

class Movimiento_friccion:

	def __init__(self, a, b):

		self.a, self.b = a, b

	def __call__(self, u, t):

		v, a, b = u, self.a, self.b 

		return a - b*v

class Tiro_Parabolico:

	def __init__(self, v, g, friccion = False, B = 0):

		self.v, self.g, self.friccion, self.B = v, g, friccion, B

	def __call__(self, u, t):

		x, vx, y, vy = u 
		g, B = self.g, self.B

		if self.friccion == True:

			v = ((vx)**2 + (vy)**2)**(1/2) 	

			return np.array([vx, -B*v*vx, vy, -g - B*v*vy])

		else:

			return np.array([vx, 0, vy, -g]) 

class Pendulo:

	def __init__(self, g, l, m, q = 0, Fd = 0, omega = 0, Linear = True):

		self.g, self.l, self.m = g, l, m
		self.q, self.Fd, self.omega = q, Fd, omega

	def __call__ (self, u, t):

		theta, vtheta = u
		g,l,  = self.g, self.l 
		q, Fd, omega = self.q, self.Fd, self.omega 
				
		if Linear:

			return np.array([vtheta, (-g/l)*theta - q*vtheta + Fd*np.sin(omega*t)])

		else: 

			return np.array([vtheta, (-g/l)*np.sin(theta) - q*vtheta + Fd*np.sin(omega*t)])
	
