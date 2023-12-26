#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>
#include <time.h>

#define ARR_SIZE 1000

int main(int argc, char *argv[]) {
	int rank,size,code,tag=100;
    double timee;
	MPI_Status status;

	float buff[ARR_SIZE];
    srand(time(NULL));
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0){
		for (int i = 0; i < ARR_SIZE; i++) buff[i] = ((float)rand()/(float)RAND_MAX*10);
        timee = MPI_Wtime();
        for (int i = 0 ; i < 1000; i++ ) {
            MPI_Send(buff, ARR_SIZE, MPI_FLOAT, 1, tag, MPI_COMM_WORLD);
		    code = MPI_Recv(buff, ARR_SIZE, MPI_FLOAT, 1, tag, MPI_COMM_WORLD, &status);
        }
        timee = MPI_Wtime() - timee;
        printf("Elapsed time is %fs.\n", timee);
	}
	else if (rank == 1) {
        for (int i = 0; i < 1000; i++) {
            code = MPI_Recv(buff, ARR_SIZE, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, &status);
            MPI_Send(buff, ARR_SIZE, MPI_FLOAT, 0, tag, MPI_COMM_WORLD);
        }
	}
	
	MPI_Finalize();
	return 0;
}