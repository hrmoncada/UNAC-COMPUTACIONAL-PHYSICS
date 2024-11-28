'''
https://medium.com/@mlblogging.k/simulating-brownian-motion-and-stock-prices-using-python-17b6b4bd2a1
Simulating Brownian Motion ( and Stock Prices ) using Python
Simulation of a 2-D Brownian Motion
'''


import random
import numpy as np
import plotly.express as px

def simulate_2d_bm(nsteps=1000, t=0.01):
    x = np.cumsum([ np.random.randn()*np.sqrt(t) for i in range(nsteps) ])
    y = np.cumsum([ np.random.randn()*np.sqrt(t) for i in range(nsteps) ])
    return list(x), list(y)

x, y = simulate_2d_bm()
fig = px.line({ 'x' : x, 'y' : y }, x='x', y='y')
fig.show()
