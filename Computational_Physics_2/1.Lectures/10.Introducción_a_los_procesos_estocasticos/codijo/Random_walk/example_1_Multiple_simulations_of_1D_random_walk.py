'''
https://medium.com/@mlblogging.k/simulating-brownian-motion-and-stock-prices-using-python-17b6b4bd2a1
Simulating Brownian Motion ( and Stock Prices ) using Python
Multiple simulations of 1-D random walk
'''

import random
import numpy as np
import plotly.express as px

def simulate_1d_rw(nsteps=1000, p=0.5, stepsize=1):
    steps = [ 1*stepsize if random.random() < p else -1*stepsize for i in range(nsteps) ]
    y = np.cumsum(steps)
    x = list(range(len(y)))

    return x, list(y)

simulation_data = {}
nsims = 5
for i in range(nsims):
    x, y = simulate_1d_rw()
    simulation_data['x'] = x
    simulation_data['y{col}'.format(col=i)] = y

ycols = [ 'y{col}'.format(col=i) for i in range(nsims) ]
fig = px.line(simulation_data, x='x', y=ycols)
fig.show()

