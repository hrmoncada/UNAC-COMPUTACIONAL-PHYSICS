#!/usr/bin/env python
"""
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
for python3
"""
import mpi4py.MPI as MPI

comm = MPI.COMM_WORLD
rang = comm.Get_rank()
nprocs = comm.Get_size()

if rang == 0:
    data = [[1.0, 2.0, 3.0, 4.0, 4.5], \
           [5.0, 6.0, 7.0, 8.0, 9.5], \
           [9.0, 10.0, 11.0, 12.0, 12.5], \
          [13.0, 14.0, 15.0, 16.0, 16.5]]
else:
    data = None
    data = comm.scatter(data, root=0)
    print('rank=',rang,'Results:',data)
