#include <stdio.h>
#include <stdlib.h>
#include <mpi/mpi.h>
#include <unistd.h>

#define NAME_MAX_LENGTH 128

int main(int argc, char *argv[]) {
    
    int rank, size;
    char hostname[NAME_MAX_LENGTH];

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    gethostname(hostname, NAME_MAX_LENGTH);

    printf("Hello World from Process %d (size=%d) on machine '%s'\n", rank, size, hostname);

    MPI_Finalize();

    return 0;
}