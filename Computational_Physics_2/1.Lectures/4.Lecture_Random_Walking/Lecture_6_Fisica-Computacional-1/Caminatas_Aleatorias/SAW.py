"""
Caminatas aleatorias autoevitante 

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import sys
import numpy as np
import matplotlib.pyplot as plt

sys.path.append("../")
from PhysicsPy.Random_Walk import Random_Walk_Avoiding, Random_Walk_2D 

Walkers = Random_Walk_Avoiding(0.25, 20)

r = np.zeros(21)
P = np.zeros(20)
for i in range(5):

	x, y, P = Walkers.Walk()

	plt.plot(x, y, label = f"{i+1}", marker = "o")

	r += (1/5)*(x**2 + y**2)
	
	del x, y 

plt.title("Caminata aleatoria autoevitante (SAW)")
plt.xlabel("x (pasos)") ; plt.ylabel("y (pasos)")
plt.grid() ; plt.legend(fancybox=True)
plt.show()

plt.title("Distancia promedio cuadratica")
plt.xlabel("tiempo (pasos)") ; plt.ylabel("Distancia")
plt.plot(r, label = r"$\langle r^2 \rangle$", marker = "o")
plt.grid() ; plt.legend(fancybox=True)
plt.show()

