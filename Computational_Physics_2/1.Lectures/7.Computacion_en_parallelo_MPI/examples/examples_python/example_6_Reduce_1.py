#!/usr/bin/env python
""" for python3
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
 """
import mpi4py.MPI as MPI
import numpy as np
import part as part

comm = MPI.COMM_WORLD
nprocs = comm.size
rank = comm.rank

# Define the size of the problem
N = 1001
start,end = part.partition(rank,nprocs,N)
vec = np.ones((end-start+1),dtype=np.float64)

# Calculate the local sum of local vectors
local_sum = vec.sum()
print("[ %d ] part : %f"%(rank, local_sum))
comm.barrier()

# Get the global sum
global_sum = comm.reduce(local_sum, op=MPI.SUM, root=0)
if rank == 0:
   print("Sum : %f"%(global_sum))
