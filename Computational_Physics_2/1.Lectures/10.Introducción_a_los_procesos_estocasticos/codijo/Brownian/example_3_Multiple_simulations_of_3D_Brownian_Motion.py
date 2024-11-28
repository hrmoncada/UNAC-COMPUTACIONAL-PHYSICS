'''
https://medium.com/@mlblogging.k/simulating-brownian-motion-and-stock-prices-using-python-17b6b4bd2a1
Simulating Brownian Motion ( and Stock Prices ) using Python
Simulation of 3-D Brownian Motion for 10K steps
'''


import random
import numpy as np
import plotly.express as px

def simulate_3d_bm(nsteps=10000, t=0.01):
    x = np.cumsum([ np.random.randn()*np.sqrt(t) for i in range(nsteps) ])
    y = np.cumsum([ np.random.randn()*np.sqrt(t) for i in range(nsteps) ])
    z = np.cumsum([ np.random.randn()*np.sqrt(t) for i in range(nsteps) ])
    return list(x), list(y), list(z)

x, y, z = simulate_3d_bm()
fig = px.line_3d({ 'x' : x, 'y' : y, 'z' : z }, x='x', y='y', z='z')
fig.show()
