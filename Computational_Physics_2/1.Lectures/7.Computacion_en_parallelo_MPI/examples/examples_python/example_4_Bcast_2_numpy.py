#!/usr/bin/env python
"""
for python3
"""

import mpi4py.MPI as MPI
import numpy as np

comm = MPI.COMM_WORLD
rang = comm.Get_rank()
nprocs = comm.Get_size()

if rang == 0:
   f = open('data.txt','r')
   n = np.array([int(float(f.read()))], dtype=int)
else:
   n = np.zeros(1, dtype=int)

comm.Bcast(n,root=0)

print("Process ",rang,"has received ",n[0])
