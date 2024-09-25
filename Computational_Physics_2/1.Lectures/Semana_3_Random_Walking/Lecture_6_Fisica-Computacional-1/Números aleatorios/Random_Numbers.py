"""
Generado números aleatorios 

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional

sáb 08 may 2021 13:11:11 CDT 

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import numpy as np
from Random import Random_Number
import matplotlib.pyplot as plt

rand = Random_Number(r0=1234, a=106, c=1283, m=6075)				#Seleccionamos los parámetros para tener el generador

x = rand.random(size = 100)							#Arreglo de 100 números aleatorios

xy = rand.random(size = (400, 2))						#Matriz 400x2 de números aleatorios, corresponden (x,y) 

Oct = np.zeros((400, 2))							#Puntos que estarán sobre la esféra
theta = np.linspace(0, np.pi/2, 1001)						#Ángulo polar, corresponde a un octante de la esféra 

for point, i in zip(xy, range(len(xy))):					#Los puntos que se encuentren sobre un cuarto de circulo,
										#de radio r = 1. Es decir, los puntos que esten dentro del 
	if point[1] <= np.sqrt(1 - point[0]**2):				#área, de la función
										#		f(x) = sqrt(1 - x^2)
		Oct[i] = point							#corresponden a los puntos que estarán sobre la esféra

z = np.sqrt(1 - (Oct[:,0]**2 + Oct[:,1]**2))					#Puntos sobre la esféra de radio r=1

#Sección de gráficas
plt.style.use("seaborn")

fig = plt.figure(figsize=(10, 10))

ax1 = fig.add_subplot(2, 2, 1)
ax1.set_title(r"Números aleatorios: $r_{i} \; vs \; i$")
ax1.plot(x, color = "green", marker = "o", label = "$r_i$")
ax1.set_xlabel("$i$") ; ax1.set_ylabel("$r_{i}$")
ax1.legend() ; ax1.grid(True)

ax2 = fig.add_subplot(2, 2, 2)
ax2.set_title(r"Números aleatorios: Plano $xy$")
ax2.scatter(xy[:,0], xy[:,1] , color = "orange", marker = "o")
ax2.set_xlabel("$x$") ; ax2.set_ylabel("$y$") ; ax2.grid(True)

ax3 = fig.add_subplot(2, 2, 3)
ax3.set_title(r"Números aleatorios: Octante")
ax3.scatter(Oct[:,0], Oct[:,1] , color = "blue", marker = "o")
ax3.plot(np.cos(theta), np.sin(theta), color = "red", label = "$x^2 + y^2$")
ax3.set_xlabel("$x$") ; ax3.set_ylabel("$y$") ; ax3.legend() ; ax3.grid(True)

ax4 = fig.add_subplot(2, 2, 4, projection='3d')
ax4.set_title("Números aleatorios: Esfera")
ax4.scatter(Oct[:,0], Oct[:,1], z, color = "purple", marker="o")
ax4.set_xlabel("$x$") ; ax4.set_ylabel("$y$")  ; ax4.grid(True)

fig.tight_layout()
plt.show()
