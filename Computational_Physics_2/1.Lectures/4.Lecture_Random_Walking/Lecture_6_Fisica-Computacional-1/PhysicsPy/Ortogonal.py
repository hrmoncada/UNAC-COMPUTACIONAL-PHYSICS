import numpy as np
import matplotlib.pyplot as plt

def H(x, n):

	if n==0:

		return np.ones(len(x))
    
	elif n==1:

		return 2*x

	else:

		return 2*x*H(x,n-1)-2*(n-1)*H(x,n-2)

def P(x, n):

	if n == 0: 

		return np.ones(len(x))

	elif n == 1:

		return x

	else:

		return  (( x*(1+ 2*(n-1))*P(x, n - 1) - (n-1)*P(x, n - 2) )/(n))
	 

x = np.linspace(-2,2,1001)

for i in range(6):
    
    plt.plot(x, H(x,i), label=f"$P_{i}$")
    
plt.title("Polinomios de Legendre")
plt.grid() ; plt.legend()
plt.show()
