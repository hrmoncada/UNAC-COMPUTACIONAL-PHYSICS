from math import log10
import numpy as np 

class EquationsSolver:

	def __init__(self, f, df = None):

		self.df = df

		if isinstance(f, (int, float)):

			self.f = lambda x: f 

		elif callable(f): 

			self.f = f

		else: 

			raise Exception("La función no fue definida")

	def InitialCondition(self, x0, tol, maxiter = None):

		if isinstance(x0, (int, float)):
	
			self.point, self.interval = True, False
			x0 = float(x0)

		else:

			self.point, self.interval = False, True
			x0 = list(x0)

		self.x0, self.tol, self.maxiter = x0, tol, maxiter

class Biseccion(EquationsSolver):

	def Solve(self):

		if isinstance(self.x0, (int, float)):
	
			raise ValueError("No se definió un intervalo")

		a, b  = self.x0 
		f, tol = self.f, self.tol
		
		if a > b:

        		raise ValueError("Intervalo mal definido")

		if f(a) * f(b) >= 0.0:
        
			raise ValueError("La función debe cambiar de signo en el intervalo")

		if tol <= 0:

        		raise ValueError("La cota de error debe ser un número positivo")
		
		x = (a + b) / 2.0

		while True:

			if b - a < tol:

				#return round(x, int(abs(log10(tol)))
				return x
      
			elif np.sign(f(a)) * np.sign(f(x)) > 0:
	
            			a = x

			else:
				b = x
			
			x = (a + b) / 2.0

class Newton_Rhapson(EquationsSolver):

	def Solve(self):
   
		x, f, df, maxiter, tol = self.x0, self.f, self.df, self.maxiter, self.tol 
	
		if df(x) == 0:

			raise ValueError("Division por cero")
    		
		for i in range(maxiter):

		        dx = -f(x) / df(x) 

		        x = x + dx

		        if abs(dx / x) < tol and abs(f(x)) < tol:

		            return x

		raise RuntimeError(f"No hubo convergencia después de {maxiter} iteraciones")

class Secant(EquationsSolver):

	def Solve(self):

		f, maxiter, tol = self.f, self.maxiter, self.tol 
		a, b = self.x0	

		i = 0

		while i < maxiter:
			
			try: 
		
				x = b - float(f(b))/(float(f(b) - f(a))/(b - a))

				er = abs(x-b)/abs(x)

			except ZeroDivisionError:

				print("Error en el denominador, para x = ", x)

				break

			if er < tol:

				return x

			a = b
			b = x
			i += 1
    		
		return x
