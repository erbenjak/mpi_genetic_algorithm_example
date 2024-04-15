# Example MPI genetic algorithm

This example is used to create a framework to place different solvers in an evolutionary setting, which communicates using MPI.

# General idea
A "secret" solution is created which creates a string of n random digits. The initial solution will be a vector n zeros.
One "solver" will be able to replace up to k digits by some random even digit, another solver will do the same for odd digits.

They will exchange their solutions and once they have guessed some $\tau * n$ number of digits this is returned as the solution.

The combination of solutions depends on the correctness of their respective solutions. The solvers should execute their 
adaptations in parallel. The new solution will be created by one orchestrating processor.