//  C++

#include <iostream>
#include <unistd.h>
#include <omp.h>

using namespace std;

int main () {

    // Serial Region  (master thread)
    // Parameters of the Application
    int len=30;
    char name[30];

    // OpenMP Parameters
    int id, nthreads;

    // Master thread obtains information about itself and its environment.
    nthreads = omp_get_num_threads();       // get number of threads
    id = omp_get_thread_num();              // get thread
    gethostname(name,len);                  // get run-host name
    cout << "SERIAL REGION:     Runhost:" << name << "   Thread:" << id << " of " << nthreads << " thread    hello, world" << endl;

    // Open parallel region.
    // Each thread obtains information about itself and its environment.
    #pragma omp parallel private(name,id,nthreads)
    {nthreads = omp_get_num_threads();      // get number of threads
     id = omp_get_thread_num();             // get thread 
     gethostname(name,len);                 // get run-host name
     cout << "PARALLEL REGION:   Runhost:" << name << "   Thread:" << id << " of " << nthreads << " threads   hello, world" << endl;
    }
    // Close parallel region.

    // Serial Region  (master thread)
    cout << "SERIAL REGION:     Runhost:" << name << "   Thread:" << id << " of " << nthreads << " thread    hello, world" << endl;
    return 0;
}
~ 