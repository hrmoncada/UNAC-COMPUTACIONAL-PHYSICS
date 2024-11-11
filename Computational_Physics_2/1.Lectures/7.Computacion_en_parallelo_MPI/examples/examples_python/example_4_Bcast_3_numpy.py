from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()  # Rank of the process
size = comm.Get_size()   # Total number of processes

# Only the root process (rank 0) creates the data
if rank == 0:
    data = np.arange(100, dtype='i')  # Array of 100 integers (0 to 99)
else:
    data = np.empty(100, dtype='i')   # Placeholder array for other processes

# Broadcast the data from root to all processes
comm.Bcast(data, root=0)

# Each process now has access to 'data'
print(f"Process {rank} received data: {data[:10]}...")  # Displaying first 10 elements
