#!/usr/bin/env python
"""
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
for python3
mpirun -np 4 python point_a_point_numpy.py
"""
import mpi4py.MPI as MPI
import numpy as np

rang = MPI.COMM_WORLD.Get_rank()
nprocs = MPI.COMM_WORLD.Get_size()
master = 0
tagm = 101
tagr = 201

if rang == master:
   print(’Enter integer number:’)
   n = input()
   data = np.array([n],dtype=’i’)

   for i in range(1,nprocs):
      MPI.COMM_WORLD.Send([data,MPI.INT],dest=i,tag=tagm)

   for i in range(1,nprocs):
      MPI.COMM_WORLD.Recv([data,MPI.INT],source=i,tag=tagr)
      print("Master ",rang," received from slave ",i,": n=",data[0])
else:
   data = np.empty(1,dtype=’i’)
   MPI.COMM_WORLD.Recv([data,MPI.INT],source=0,tag=tagm)
   print("Slave ",rang," has received n=",data[0]," from ",master)
   data[0] = data[0]*rang
   MPI.COMM_WORLD.Send([data,MPI.INT],dest=0,tag=tagr)
