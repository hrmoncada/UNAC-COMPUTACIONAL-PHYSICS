import numpy as np
import matplotlib.pyplot as plt
from timeit import default_timer

#pasos = 500

#x = np.random.random(pasos)
#y = np.random.random(pasos)

#x2 = np.cumsum(np.where((x<=0.5) == True, 1, -1))	
#y2 = np.cumsum(np.where((y<=0.5) == True, 1, -1))	

def Walk(N, p):

	X = np.random.random(N)					
	steps = np.where((X<=p) == True, 1, -1)			 
	new_steps = np.zeros(N)					

	for i in range(len(new_steps)-1):

		new_steps[i + 1] = sum(steps[:i +1])

	return new_steps

def Walk2(N, p):

	X = np.random.random(N)					
	steps = np.cumsum(np.where((X<=p) == True, 1, -1))	
	
	return steps

Resultados = []

for i in range(1000):

	I = default_timer()
	x = Walk(500, 0.5)
	F = default_timer() - I 

	I1 = default_timer()
	x1 = Walk2(500, 0.5)
	F1 = default_timer() - I1 
	
	Resultados.append(F1 < F)
	
Filtrar = np.where(np.array(Resultados) == True, 1, 0)

unique, counts = np.unique(Filtrar, return_counts=True)

print(dict(zip(unique, counts)))

#plt.plot(x) ; plt.plot(x1)
#plt.grid()
plt.show()
