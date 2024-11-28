'''
https://medium.com/@mlblogging.k/simulating-brownian-motion-and-stock-prices-using-python-17b6b4bd2a1
Simulating Brownian Motion ( and Stock Prices ) using Python
Simulation of 2-D random walk for 10K steps
'''
import random
import numpy as np
import plotly.express as px

def simulate_3d_rw(nsteps=10000, stepsize=1):

    deltas = [ (0,0,-1*stepsize), (0,-1*stepsize,0), (-1*stepsize,0,0),\
               (0,0,1*stepsize), (0,1*stepsize,0), (1*stepsize,0,0) ]

    steps = [ list(random.choice(deltas)) for i in range(nsteps) ]
    steps = np.array(steps)
    steps = np.cumsum(steps,axis=0)
    z = list(steps[:,2])
    y = list(steps[:,1])
    x = list(steps[:,0])

    return x, y, z

x, y, z = simulate_3d_rw()
fig = px.line_3d({ 'x' : x, 'y' : y, 'z' : z }, x='x', y='y', z='z')
fig.show()
