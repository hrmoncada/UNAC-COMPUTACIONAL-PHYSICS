#!/usr/bin/env python
"""
https://indico.in2p3.fr/event/20625/contributions/101997/attachments/67854/95270/mpi.pdf
for python3

$ mpirun -np 4 python example_2_Hello_World.py 
Hello! I am process 0 of 4 on lola.
Hello! I am process 1 of 4 on lola.
Hello! I am process 2 of 4 on lola.
Hello! I am process 3 of 4 on lola.

"""
import mpi4py.MPI as MPI

rank = MPI.COMM_WORLD.Get_rank()
numtasks = MPI.COMM_WORLD.Get_size()
hostname = MPI.Get_processor_name()

mess = "Hello! I am process %d of %d on %s."

print(mess % (rank, numtasks, hostname))
