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
        std::cout << "MPI_Init failed" << std::endl;
    }

    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &id);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &p);

    if (id == 0)
    {
        std::cout << "welcome to this very simple mpi algorithm demonstration!" << std::endl;
        std::cout << "Number of processes: " << p << std::endl;

        // create a vector with 10 random digits
        int vector[10];
        for (int i = 0; i < 10; i++)
        {
            vector[i] = rand() % 10;
        }

        // print the generated vector
        std::cout << "Generated vector: ";
        for (int i = 0; i < 10; i++)
        {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;

        // send the vector to process 1
        ierr = MPI_Send(vector, 10, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else
    {
        // expect to receive the vector from process 0
        int received_vector[10];
        ierr = MPI_Recv(received_vector, 10, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (ierr != MPI_SUCCESS)
        {
            std::cout << "Error receiving the vector" << std::endl;
        }

        std::cout << "Process " << id << " received the vector: ";
        for (int i = 0; i < 10; i++)
        {
            std::cout << received_vector[i] << " ";
        }
        std::cout << std::endl;
    }

    // communicate that this process is done
    std::cout << "Process " << id << " is done!" << std::endl;

    // Finalize MPI
    ierr = MPI_Finalize();
    return 0;
}