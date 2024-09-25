"""
Caminatas aleatorias (Multiples caminantes en 2D) 

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional 

mar 20 abr 2021 09:36:14 CDT 

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import sys
import numpy as np
import matplotlib.pyplot as plt

sys.path.append("../")
from PhysicsPy.Random_Walk import Random_Walk_2D

Walker = Random_Walk_2D(0.5, 20)						#Caminata en dos dimensiones, con p=0.5, 20 pasos
steps = Walker.Multiple_Walkers(5)						#Se realizan 5 caminatas

fig, (ax1,ax2) = plt.subplots(1, 2, figsize = (9,4.5))

#Gráfica de las caminatas
for i in range(5):

	ax1.plot(steps[:,i],steps[:,i+1], label = f"{i+1}", marker = "o")

ax1.set_title("Caminatas aleatorias en 2D")
ax1.set_xlabel("x (pasos)") ; ax1.set_ylabel("y (pasos)")
ax1.legend() ; ax1.grid()

r = Walker.Mean_Distances()							#Distancia promedio

#Gráfica de la distacia recorrida
ax2.set_title("Distancia promedio recorrida")
ax2.plot(r, label = r"$\langle x^2 \rangle \; vs \; t$")
ax2.set_xlabel("tiempo (pasos)") ; ax2.set_ylabel(r"$\langle r^2 \rangle$")
ax2.legend() ; ax2.grid()

fig.tight_layout()
plt.show()
