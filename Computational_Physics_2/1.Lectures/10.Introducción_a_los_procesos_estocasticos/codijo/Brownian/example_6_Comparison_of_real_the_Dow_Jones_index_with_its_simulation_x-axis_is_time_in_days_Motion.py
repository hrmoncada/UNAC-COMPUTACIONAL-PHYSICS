import pandas_datareader.data as web
import numpy as np
import plotly.express as px
import random

def simulate_1d_gbm(nsteps=1000, t=1, mu=0.0001, sigma=0.02, start=1):
    steps = [ (mu - (sigma**2)/2) + np.random.randn()*sigma for i in range(nsteps) ]
    y = start*np.exp(np.cumsum(steps))
    x = [ t*i for i in range(nsteps) ]
    return x, y

df = web.DataReader('^DJI', 'stooq')
mask = ( '2022-01-01' <= df.index ) & ( df.index <= '2022-12-31' )
df = df[mask]
prices = np.flip(df['Close'].values)

logprices = np.log(prices)
logreturns = logprices[1:] - logprices[:-1]
mu = np.mean(logreturns)
sigma = np.std(logreturns)
nsteps = logprices.shape[0]

x, y = simulate_1d_gbm(nsteps=nsteps, mu=mu, sigma=sigma, start=prices[0])

data = {}
data['x'] = x
data['Simulation'] = y
data['DowJonesIndex'] = prices

fig = px.line(data,x='x', y=['DowJonesIndex', 'Simulation'])
fig.show()

