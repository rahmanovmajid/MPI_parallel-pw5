#include <stdio.h>
#include <mpi/mpi.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    int rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    (rank%2 == 0) // ternary operator
        ? printf("I am process %d, my rank is even.\n", rank)
        : printf("I am process %d, my rank is odd.\n", rank);

    MPI_Finalize();
    
    return 0;
}