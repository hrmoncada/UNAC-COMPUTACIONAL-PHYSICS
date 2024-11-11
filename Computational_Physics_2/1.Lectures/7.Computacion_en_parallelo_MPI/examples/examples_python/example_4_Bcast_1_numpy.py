#!/usr/bin/env python
"""
for python3

"""
import mpi4py.MPI as MPI

comm = MPI.COMM_WORLD
rang = comm.Get_rank()
nprocs = comm.Get_size()


if rang == 0:
   f = open('data.txt','r')
   n = int(float(f.read()))
else:
   n = None

n = comm.bcast(n,root=0)
print("Process ",rang,"has received ",n)
