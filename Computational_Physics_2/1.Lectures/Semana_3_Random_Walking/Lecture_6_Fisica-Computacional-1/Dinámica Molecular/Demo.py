"""
Simulación de dinámica molecular (Base que puede mejorarse con POO)

Luis Eduardo Sánchez González

Universidad Autonoma de Coahuila
Facultad de Ciencias Físico Matemáticas

jue 27 may 2021 17:24:20  
"""
import numpy as np 
import matplotlib.pyplot as plt
from copy import * 
import matplotlib.animation as animation

def lattice_pos(npart,r):

	#Calculo cantidad de celdas por lado
	n = int(np.ceil(np.sqrt(npart)))
    
	#calculo el centro de la celda
	nf = 1.0/float(n)
    
	#Calculo las posiciones de todas las celdas disponibles agregando un r% de randomizacion
    
	celdas = [[i*nf +0.5*nf + r*np.random.rand(),j*nf + 0.5*nf+ r*np.random.rand()]
			for i in range(n) for j in range(n)]
    
	#Mezclo las posiciones de las celdas
	np.random.shuffle(celdas)
    
	X = np.array(celdas[0:npart])
	return X

def vel_ini(npart,temp_red):

	V = np.random.rand(npart,2)-0.5*np.ones((npart,2))
    
	#Calculamos la velocidad del centro de masa
	Vx = sum(V[:,0])/npart
	Vy = sum(V[:,1])/npart
    
	#Calculamos la velocidad cuadratica media
	V2 = sum(sum(V**2))/npart
    
	#Factor de escala para temperatura
	fs = np.sqrt(2*temp_red/V2)
    
	#Elimino la velocidad del centro de masa y escalo
	V[:,0] = (V[:,0] - Vx)*fs
	V[:,1] = (V[:,1] - Vy)*fs
    
	return V

def init(npart,box,temp_red,dt_red,sigma):
  
	r = 0.01
	X = lattice_pos(npart,r)
    
	#Escalo posiciones al tamanio de caja y lo reduzco con sigma
	X = (X*box)/sigma
	V = vel_ini(npart,temp_red) 
    
	return X,V
    
def force(npart,X,rcut,box,epsilon):

	#inicializo las fuerzas a 0.0 y la energia a 0.0
	F = np.zeros((npart,2))
	Epot = 0.0
    
	#Calculo la energia de cutoff en unidades reducidas
	rci6 = 1.0/rcut**6
	rci12= rci6**2
	Ecut = 4.0*(rci12 -rci6)
    
	#Calculo la fuerza sobre todos los pares de particulas
	for i in range(npart-1):
		
		for j in range(i+1,npart):
		
			rx = X[i,0] - X[j,0]
			rx = rx - box*np.rint(rx/box)
			ry = X[i,1] - X[j,1]
			ry = ry - box*np.rint(ry/box)
			r2 = rx**2 + ry**2
            
			if r2 < rcut**2:

				r2i = 1/r2
				r6i = r2i**3
				ff = 48.0*r2i*r6i*(r6i-0.5)
                
				# F tiene unidades de reducidas
				F[i,0] = F[i,0] + ff*rx
				F[j,0] = F[j,0] - ff*rx

				F[i,1] = F[i,1] + ff*ry
				F[j,1] = F[j,1] - ff*ry

				Epot = Epot + 4.0*r6i*(r6i-1.0) - Ecut
                
	return [F,Epot*epsilon] #Fuerza en unidades reducidas y energia en kJ/mol

def pos(npart,X,V,F,dt,box,m):

	Xnew = X + V*dt + (F/(2.0*m))*dt**2
    
	#Se fija si la partícula salió de la caja y la transporta a
	#la posición correspondiente de su imagen
	np.where(Xnew[:,0] > box, Xnew[:,0] - box, Xnew[:,0])
	np.where(Xnew[:,0] < 0.0, box + Xnew[:,0], Xnew[:,0])
	np.where(Xnew[:,1] > box, Xnew[:,1] - box, Xnew[:,1])
	np.where(Xnew[:,1] < 0.0, box + Xnew[:,1], Xnew[:,1])
    
	return Xnew

def vel(npart,V,F,Fnew,dt,m):

	Vnew = V + (0.5/m)*(Fnew + F)*dt
    
	V2 = sum(sum(Vnew**2))
	Ekin = 0.5*V2*epsilon
    
	return Vnew, Ekin
    
def inicializar(npart, box, temperatura, dt, sigma, epsilon, masa):
   
	NA = 6.02e23 # 1/mol
	kB = 1.381e-23 # J/K
    
	rcut = box/2.0 # A (unidades reales)
    
	#reduzco el tiempo
	t_unit = (sigma*1e-10) * np.sqrt(masa*1e-3/(1000*epsilon))
	dt_red = dt/t_unit

	#reduzco la temperatura
	temp_unit = 1.0/(kB/(1000*epsilon/NA))
	temp_red = temperatura/temp_unit

	#reduzco la masa
	m_unit = masa*1e-3/NA
	m = 1

	#Posiciones y Velocidad inicial
	X, V = init(npart,box,temp_red,dt_red,sigma)

	#Calculo fuerzas iniciales
	F,Epot = force(npart,X,rcut/sigma,box/sigma,epsilon)

	unit_red = {'t_unit': t_unit, 'T_unit': temp_unit, 'm_unit': m_unit, 'E_unit':epsilon, 'x_unit': sigma,
			'box': box/sigma, 'rcut':rcut/sigma, 'Temp0':temperatura, 'sigma':sigma, 'epsilon':epsilon,
			'dt':dt, 'm':m}
    
	return X, V, F, unit_red

def simular(nsteps, X, V, F, unit_red, tau_ber, plot_freq): 

	sigma = unit_red['sigma'] ; 
	epsilon = unit_red['epsilon']
	dt = unit_red['dt']/unit_red['t_unit']
	box = unit_red['box']
	temp0 = unit_red['Temp0']
	m = unit_red['m']
	rcut = unit_red['rcut']
	temp_unit = unit_red['T_unit']

	plt.style.use("seaborn")    
	fig = plt.figure()
	ax1 = fig.add_subplot(2,2,1)
	ax2 = fig.add_subplot(2,2,3)
	ax3 = fig.add_subplot(2,2,2)

	#inicializo
	E = np.zeros((nsteps,2))
	T = np.zeros((nsteps,1))
    
	if tau_ber > 0:
		berendsen = True
	else:
		berendsen = False
     
	def update(i):
	
		#Calculo Posicion
		global npart, X, V, F, dt, box, m, sigma, epsilon
		
		Xnew = pos(npart,X,V,F,dt,box,m= unit_red['m'])
		
		Fnew, Epot = force(npart,Xnew,rcut,box,epsilon)
		E[i,0] = Epot
    
        	#Calculo velocidad
		Vnew, Ekin = vel(npart,V,F,Fnew,dt,m= unit_red['m'])
		E[i,1] = Ekin
		T_i = sum(sum(Vnew**2))/(2*npart)*temp_unit 
		T[i] = T_i
    
		if berendsen:
			l = np.sqrt(1 + (dt/tau_ber)*(temp0/T_i - 1))
			Vnew = Vnew*l
    
		#Actualizo variables
		X = copy(Xnew)
		V = copy(Vnew)
		F = copy(Fnew)
    
		ax1.clear()
		ax1.plot(X[:,0]*sigma,X[:,1]*sigma,'b.')
    
		ax1.axis('equal')
		ax1.set_aspect('equal', 'box')
		ax1.set_xlim(0,box*sigma)
		ax1.set_ylim(0,box*sigma)
        
		ax2.clear()
		ax2.plot((E[0:i,0]+ E[0:i,1])/npart,'r', label = 'Total')
		ax2.plot(E[0:i,0]/npart,'g', label = 'Potencial')
		ax2.plot(E[0:i,1]/npart,'b', label = 'Cinetica')
		ax2.set_ylabel('E(kJ/mol)')
		ax2.legend(loc='upper center', bbox_to_anchor=(0.5, -0.1), ncol=3, fancybox=True, shadow=True)
		   
		ax3.clear()
		ax3.plot(T[0:i],'r')
		ax3.plot((i+1)*[temp0],'k--')
		ax3.set_xlabel('Paso')
		ax3.set_ylabel('T(K)')
            
	ani = animation.FuncAnimation(fig, update, range(nsteps), interval = 100)
	plt.show()
            
	return X, V, F
    
if __name__ == "__main__":
    
	nsteps = 2000
	npart  =  144
	box = 40
	temperatura = 119.8 #K
	dt = 1e-14 # en segundos 
	sigma = 3.405 #A
	epsilon = 0.996 #kJ/mol
	masa = 39.95 #g/mol
	tau_ber = 1
	plot_freq = 1

	X, V, F, unit_red = inicializar(npart, box, temperatura, dt, sigma, epsilon, masa)
	unit_red['Temp0'] = 200
	tau_ber = 1.0
	nsteps = 2000
	X, V, F = simular(nsteps, X, V, F, unit_red, tau_ber, plot_freq)
