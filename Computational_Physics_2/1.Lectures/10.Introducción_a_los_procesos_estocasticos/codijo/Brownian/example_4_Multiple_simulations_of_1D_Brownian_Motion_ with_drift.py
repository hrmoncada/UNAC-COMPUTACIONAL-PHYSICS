import random
import numpy as np
import plotly.express as px

def simulate_1d_bm_with_drift(nsteps=1000, t=0.01, mu=0.5):
    steps = [ mu*0.01 + np.random.randn()*np.sqrt(t) for i in range(nsteps) ]
    y = np.cumsum(steps)
    x = [ t*i for i in range(nsteps) ]
    return x, y

nsims = 5
simulation_data = {}
for i in range(nsims):
    x, y = simulate_1d_bm_with_drift()
    simulation_data['y{col}'.format(col=i)] = y
    simulation_data['x'] = x

ycols = [ 'y{col}'.format(col=i) for i in range(nsims) ]
fig = px.line(simulation_data, x='x', y=ycols)
fig.show()
