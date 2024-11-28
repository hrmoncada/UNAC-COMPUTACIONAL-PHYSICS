'''
https://medium.com/@mlblogging.k/simulating-brownian-motion-and-stock-prices-using-python-17b6b4bd2a1
Simulating Brownian Motion ( and Stock Prices ) using Python
Multiple simulations of 1-D Brownian Motion
'''

import random
import numpy as np
import plotly.express as px

def simulate_1d_bm(nsteps=1000, t=0.01):
    steps = [ np.random.randn()*np.sqrt(t) for i in range(nsteps) ]
    y = np.cumsum(steps)
    x = [ t*i for i in range(nsteps) ]
    return x, y

nsims = 5
simulation_data = {}
for i in range(nsims):
    x, y = simulate_1d_bm()
    simulation_data['y{col}'.format(col=i)] = y
    simulation_data['x'] = x

ycols = [ 'y{col}'.format(col=i) for i in range(nsims) ]
fig = px.line(simulation_data, x='x', y=ycols)
fig.show()
