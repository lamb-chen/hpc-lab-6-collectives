#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  MPI_Init(&argc, &argv);
  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (size != 2) {
    if (rank == 0) {
      fprintf(stderr, "Must run with only two ranks\n");
    }
    MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
  }

  // Try to avoid this being buffered by MPI with a large message size
  int msg_size = 10000000;
  int * large_buffer = malloc(sizeof(int) * msg_size);
  int * recv_buffer = malloc(sizeof(int) * msg_size);

  for (int i = 0; i < msg_size; ++i)
    large_buffer[i] = (rank+1)%2;

  if (rank == 0) {
    MPI_Send(large_buffer, msg_size, MPI_INT, 1, 99, MPI_COMM_WORLD);
    MPI_Recv(recv_buffer, msg_size,MPI_INT, 1, 99, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  } else {
    MPI_Send(large_buffer, msg_size, MPI_INT, 0, 99, MPI_COMM_WORLD);
    MPI_Recv(recv_buffer, msg_size,MPI_INT, 0, 99, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }

  // Check solution
  int correct = 1;
  for (int i = 0; i < msg_size; ++i) {
    if (recv_buffer[i] != rank) {
      correct = 0;
      break;
    }
  }

  if (correct)
    printf("Rank %d: correct!\n", rank);
  else
    printf("Rank %d: *not* correct!\n", rank);
	
  free(large_buffer);
  free(recv_buffer);

  MPI_Finalize();
}
