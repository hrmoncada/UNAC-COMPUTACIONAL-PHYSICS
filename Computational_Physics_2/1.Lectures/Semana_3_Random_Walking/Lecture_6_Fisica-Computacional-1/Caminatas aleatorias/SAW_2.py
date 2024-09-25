"""
Caminatas aleatorias autoevitante 

Luis Eduardo Sánchez González

Facultad de Ciencias Físico Matemáticas
Física Computacional 

lun 26 abr 2021 09:11:27 CDT 

Repositorio: https://github.com/Luis2501/Fisica-Computacional-1
"""
import sys
import numpy as np
import matplotlib.pyplot as plt
sys.path.append("../")
from PhysicsPy.Random_Walk import Random_Walk_Avoiding 

def Distance(M, N):

	Walkers = Random_Walk_Avoiding(0.25, N)

	r = np.zeros(N + 1)

	P = np.zeros(M)

	for i in range(M):

		x, y, P[i] = Walkers.Walk()		

		r += (1/5)*(x**2 + y**2)
	
		del x, y
	
	print("Promedio de iteraciones en cada caminata: ", np.mean(P))
	
	return r

if __name__ == "__main__":

	r = Distance(100, 20)
	t = np.linspace(0,20, 21)

	a, b, c = np.polyfit(t, r, 2)
	d, e, f = np.polyfit(t, np.sqrt(r), 2)	

	P = lambda t: a*(t**2) + b*t + c
	P1 = lambda t: d*(t**2) + e*t + f

	fig, (ax1,ax2) = plt.subplots(1, 2, figsize = (9,4.5))

	#Gráfica de distancia promedio
	ax1.set_title("Distancia promedio")
	ax1.plot(np.sqrt(r), label = r"$\sqrt{ \langle r \rangle } $", marker = "o")
	ax1.plot(t, P1(t), label = f"{round(d,3)}$t^{2}$  + {round(e,3)}$t$  + {round(f,3)}")
	ax1.set_xlabel("tiempo (pasos)") ; ax1.set_ylabel(r"$\langle r \rangle$")
	ax1.legend(shadow=False, fancybox=True) ; ax1.grid()

	#Gráfica de la distacia promedio cuadratica
	ax2.set_title("Distancia promedio cuadratica")
	ax2.plot(t, r, label = r"$\langle r^2 \rangle$", marker = "o")
	ax2.plot(t, P(t), label = f"{round(a,3)}$t^{2}$  + {round(b,3)}$t$  + {round(c,3)}")
	ax2.set_xlabel("tiempo (pasos)") ; ax2.set_ylabel(r"$\langle r^2 \rangle$")
	ax2.legend(shadow=False, fancybox=True) ; ax2.grid()

	fig.tight_layout()
	plt.show()
