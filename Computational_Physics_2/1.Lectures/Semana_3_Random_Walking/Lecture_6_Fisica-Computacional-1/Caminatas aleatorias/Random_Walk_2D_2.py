"""
Caminatas aleatorias (Distancia promedio en 2D) 

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
steps = Walker.Multiple_Walkers(100)						#Se realizan 100 caminatas

r = Walker.Mean_Distances()							#Distancia promedio
r2 = Walker.Mean_Distances(cuadratic=True)					#Distancia promedio cuadratica

fig, (ax1,ax2) = plt.subplots(1, 2, figsize = (9,4.5))

#Gráfica de distancia promedio
ax1.set_title("Distancia promedio")
ax1.plot(r, label = r"$\langle r \rangle \; vs \; t$")
ax1.set_xlabel("tiempo (pasos)") ; ax1.set_ylabel(r"$\langle r \rangle$")
ax1.legend() ; ax1.grid()

#Gráfica de la distacia promedio cuadratica
ax2.set_title("Distancia promedio cuadratica")
ax2.plot(r2, color="orange", label = r"$\langle r^2 \rangle \; vs \; t$")
ax2.set_xlabel("tiempo (pasos)") ; ax2.set_ylabel(r"$\langle r^2 \rangle$")
ax2.legend() ; ax2.grid()

fig.tight_layout()
plt.show()
