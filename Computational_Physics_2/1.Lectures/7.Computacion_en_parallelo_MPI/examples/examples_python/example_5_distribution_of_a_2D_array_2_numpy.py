#!/usr/bin/env python
"""
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
for python3
"""
import mpi4py.MPI as MPI
import numpy as np

comm = MPI.COMM_WORLD
rang = comm.Get_rank()
nprocs = comm.Get_size()

my_N = 5
N = my_N * nprocs
if rang == 0:
    data = np.array([[1.0, 2.0, 3.0, 4.0, 4.5], \
                     [5.0, 6.0, 7.0, 8.0, 9.5], \
                     [9.0, 10.0, 11.0, 12.0, 12.5], \
                     [13.0, 14.0, 15.0, 16.0, 16.5]], dtype=np.float64)
else:
    data = np.empty(N, dtype=np.float64)

recv_data = np.empty(my_N, dtype=np.float64)
comm.Scatter([data,my_N,MPI.DOUBLE], [recv_data,my_N,MPI.DOUBLE], root=0)
print('rank=',rang,'Results:',recv_data)
