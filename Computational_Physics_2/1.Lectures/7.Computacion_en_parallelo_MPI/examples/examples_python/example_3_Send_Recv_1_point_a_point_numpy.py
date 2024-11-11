#!/usr/bin/env python
""" 
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
for python3 

$ mpirun -np 4  python example_3_Send_Recv_1_point_a_point_numpy.py
Enter integer number:
100
Slave  1  has received n= 100  from  0
Slave  2  has received n= 100  from  0
Slave  3  has received n= 100  from  0
Master  0  received from slave  1 : n= 100
Master  0  received from slave  2 : n= 200
Master  0  received from slave  3 : n= 300
"""
import mpi4py.MPI as MPI

rang = MPI.COMM_WORLD.Get_rank()
nprocs = MPI.COMM_WORLD.Get_size()
master = 0
tagm = 101
tagr = 201

if rang == master:
   print('Enter integer number:')
   n = int(input())
   for i in range(1,nprocs):
       MPI.COMM_WORLD.send(n,dest=i,tag=tagm)
   for i in range(1,nprocs):
       n = MPI.COMM_WORLD.recv(source=i,tag=tagr)
       print("Master ",rang," received from slave ",i,": n=",n)
else:
   n = MPI.COMM_WORLD.recv(source=0,tag=tagm)
   print("Slave ",rang," has received n=",n," from ",master)
   n = n*rang
   MPI.COMM_WORLD.send(n,dest=0,tag=tagr)
