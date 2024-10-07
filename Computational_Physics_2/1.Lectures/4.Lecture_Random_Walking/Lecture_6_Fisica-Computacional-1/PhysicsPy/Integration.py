"""
Luis Eduardo Sánchez González

Universidad Autonoma de Coahuila
Facultad de Ciencias Físico Matemáticas

mié 03 feb 2021 13:10:46 CST 
"""
import numpy as np

class Integration:

	def __init__(self, f):

		self.f = f

	def Limits(self, a, b, dx):

		self.a, self.b, self.dx = a, b, dx

		if a > b:

			raise ValueError("Wrong limits, a > b")

		if a == b:

			raise ValueError("Wrong limits, a = b \n ∫ f(x) dx = 0")

		self.N = int((b-a)/dx)
	

	def Solve(self):

		self.x = np.linspace(self.a, self.b, self.N + 1)
		self.S = np.zeros(self.N)

		for i in range(self.N):

			self.i = i

			self.S[i] = self.advance()

		return sum(self.S)


class Riemann(Integration):

	def advance(self):
					
		f, x, i, a = self.f, self.x, self.i, self.a		
		dx = x[i+1] - x[i]

		if i == 0:
	
			return f(a)*dx

		else:

			return f(x[i])*dx
						
class Midpoint(Integration):

	def advance(self):

		f, x, i, a = self.f, self.x, self.i, self.a		
		dx = x[i +1] - x[i]

		return dx*f((a + dx/2.0) + i*dx)

class Trapeze(Integration):

	def advance(self):

		f, x, i = self.f, self.x, self.i		
		a, b = self.a, self.b		
		dx = x[i +1] - x[i]

		if  i == 0:

			return 0.5*(f(a) + f(b))*dx

		else: 

			return f(x[i])*dx 

class Simpson1_3(Integration):

	def advance(self):

		f, x, i = self.f, self.x, self.i		
		a, b = self.a, self.b		
		dx = x[i +1] - x[i]

		if i == 0:

			return (f(a) + f(b))*(dx/3)
		else: 

		        if i%2 == 0 :
	
            			return 2*f(x[i])*(dx/3)
 
        		else:

           			return 4*f(x[i])*(dx/3)

class Simpson3_8(Integration):

	def advance(self):

		f, x, i = self.f, self.x, self.i		
		a, b = self.a, self.b		
		dx = x[i +1] - x[i]

		if i == 0:

			return (f(a)+f(b))*3*(dx/8)
  
		else: 

			if i%3 == 0 : 

				return 2*f(x[i])*3*(dx/8)
			else:

				return 3*f(x[i])*3*(dx/8)        

class Monte_Carlo(Integration):

	def Solve(self):

		f, N = self.f, self.N		
		a, b = self.a, self.b

		self.x = a + (b - a)*np.random.random(N)
		self.y = f(a) + (f(b) - f(a))*np.random.random(N)

		self.area = len(np.where(self.y <= f(self.x))[0])/N

		self.In = np.where(self.y < f(self.x), self.y, None) 		
		self.Out = np.where(self.y >= f(self.x), self.y, None)
	
		return self.area
