import numpy as np 

class Lennard_Jones:

	def __init__(self, sigma, epsilon):
	
		self.epsilon, self.sigma = epsilon, sigma
		
	def __call__(self, r):
	
		e, s = self.epsilon, self.sigma
	
		return 4*e*((s/r)**12 - (s/r)**6)
		
	def force(self, r):
	
		e, s = self.epsilon, self.sigma
	
		return (24*e/r)*(2*((s/r)**12) - (s/r)**6)
		
if __name__ == "__main__":

	import matplotlib.pyplot as plt
	
	r = np.linspace(0.01, 4, 1001)
	
	U = Lennard_Jones(1,1)
	
	f = U.force(r)
	
	print(U(2.5), U(0.8), U(0.72))
	
	plt.style.use("seaborn")
	
	fig, (ax1,ax2) = plt.subplots(1, 2, figsize = (12,6))
	
	ax1.set_title("Potencial de Lennard-Jones")
	ax1.plot(r, U(r), label = "$U(r)$")
	ax1.set_xlabel("$r$") ; ax1.set_ylabel("$U$")
	ax1.set_ylim(-1,2) ; ax1.set_xlim(0, 4)
	ax1.grid(True) ; ax1.legend()
	
	ax2.set_title("Fuerza asociada al potencial de Lennard-Jones")
	ax2.plot(r, f, color="g", label = r"$F(r) = - \nabla U$")
	ax2.set_xlabel("$r$") ; ax2.set_ylabel("$F$")
	ax2.set_ylim(-3,2) ; ax2.set_xlim(0, 4)
	ax2.grid(True) ; ax2.legend()
	
	fig.tight_layout()
	plt.show()	 
