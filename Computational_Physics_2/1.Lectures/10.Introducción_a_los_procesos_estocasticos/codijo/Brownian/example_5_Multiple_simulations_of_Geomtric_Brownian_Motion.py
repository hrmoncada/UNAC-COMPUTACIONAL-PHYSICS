import random
import numpy as np
import plotly.express as px

def simulate_1d_gbm(nsteps=1000, t=1, mu=0.0001, sigma=0.02):
    steps = [ (mu - (sigma**2)/2) + np.random.randn()*sigma for i in range(nsteps) ]
    y = np.exp(np.cumsum(steps))
    x = [ t*i for i in range(nsteps) ]
    return x, y

nsims = 5
simulation_data = {}
for i in range(nsims):
    x, y = simulate_1d_gbm()
    simulation_data['y{col}'.format(col=i)] = y
    simulation_data['x'] = x

ycols = [ 'y{col}'.format(col=i) for i in range(nsims) ]
fig = px.line(simulation_data, x='x', y=ycols)
fig.show()
