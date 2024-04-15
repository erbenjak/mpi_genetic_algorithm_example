#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int id;
    int ierr;
    int p;

    ierr = MPI_Init(&argc, &argv);
    if (ierr != MPI_SUCCESS)
    {
        MPI_Abort(MPI_COMM_WORLD, ierr);
    }

    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &id);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &p);

    return 0;
}