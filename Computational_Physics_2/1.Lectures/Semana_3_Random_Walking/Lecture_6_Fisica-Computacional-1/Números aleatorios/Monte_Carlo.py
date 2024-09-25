"""
Monte Carlo, áres y π

El valor de π puede calcularse encontrado el valor de área de 
un cuarto de circulo de radio 1. Eso es equivalente a encontrar 
la integral de 0 a 1 de la función f(x) = sqrt(1 - x²)

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional

mar 11 may 2021 09:15:56 CDT 

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import sys
sys.path.append("../")
import numpy as np
import matplotlib.pyplot as plt
from PhysicsPy.Integration import *

print("\nMétodo de Monte Carlo - Cálculo de π\n")

Solucion = Monte_Carlo(lambda x: np.sqrt(1 - x**2))					#Instancia en el método de Monte Carlo
Solucion.Limits(0, 1, 1/1000000)								#Puntos N = 1,000,000

print("Número de puntos:", Solucion.N, "\n")

area = Solucion.Solve()									#Obtenemos el área, puntos dentros sobre N
pi, pi_r = round(4*area, 6), round(np.pi,6)

print("Área aproximada:", area, "\n")
print("Aproximación de π:", pi, "\n")
print("Error absoluto:", abs(pi_r- pi))
print("Error relativo: ", abs(pi_r-pi)*100/pi_r, "%\n")

θ = np.linspace(0, np.pi/2, 1001)											

x, In, Out = Solucion.x, Solucion.In, Solucion.Out

plt.style.use("seaborn")
plt.title(r"Método de Monte Carlo - Cálculo de $\pi$")
plt.scatter(x, In, marker="o", color="orange", label = "Points in")
plt.scatter(x, Out, marker="o", color="blue", label = "Points out")
plt.plot(np.cos(θ), np.sin(θ), color="red", label = r"$x^2 + y^2 = 1$")
plt.legend(loc="lower right", ncol=3, mode="expand",shadow=False,fancybox=True)
plt.ylim(-0.15, 1) ; plt.grid(True) ; plt.show()
