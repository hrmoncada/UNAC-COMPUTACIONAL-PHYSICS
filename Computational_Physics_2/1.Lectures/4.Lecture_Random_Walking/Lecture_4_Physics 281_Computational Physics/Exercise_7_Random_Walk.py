# https://people.astro.umass.edu/~schloerb/ph281/Programs/Exercises/7/index.htm
# exercise 7.py
import numpy as np
import matplotlib.pyplot as pl
import math
from numpy.random import RandomState

# initialize parameters                                                                                                  
r = RandomState()
ntrials = 10
nsteps = 1000
step_size = 1.

# set up to show the individual random walk tracks                                                                       
show_tracks = True

x = np.zeros(nsteps)
y = np.zeros(nsteps)
s = np.arange(nsteps)

distance_squared = np.zeros(nsteps)

# make a plot of random walk tracks if requested                                                                         
#pl.ion()

if show_tracks:
    pl.figure(1)
    pl.xlabel('X')
    pl.ylabel('Y')
    pl.title('Random Walk Tracks')
    pl.axis('equal')
    pl.grid()
    
#pl.savefig('example_7_1_Random_Walk_Tracks.png')

for trial in range(ntrials):
    # initialize for this random walker                                                                                  
    x[0] = 0.
    y[0] = 0.
    for step in range(1,nsteps):
        # take next step                                                                                                 
        t = 2.*math.pi*r.rand()
        x[step] = x[step-1] + step_size*math.cos(t)
        y[step] = y[step-1] + step_size*math.sin(t)
        # accumulate distance squared for this step for all random walkers                                               
        distance_squared[step] = distance_squared[step] + x[step]**2 + y[step]**2
    if show_tracks:
        pl.plot(x,y)

distance_squared = distance_squared/ntrials
pl.figure(2)
pl.plot(s,distance_squared,'.',label='%d'%ntrials)
pl.grid()
pl.xlabel('Step')
pl.ylabel('Mean Square Distance')
pl.title('MSD v. Steps with %d Trials'%ntrials)
#pl.savefig('example_7_2_MSD_vs_Steps_with_%d_Trials.png')
pl.show()    


