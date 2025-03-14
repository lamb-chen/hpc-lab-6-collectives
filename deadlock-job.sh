#!/bin/bash
#SBATCH --job-name=deadlock
#SBATCH --account=COMS033964
#SBATCH --nodes=2
#SBATCH --time=00:15:00
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --output=dead-job-output.out
#SBATCH --partition=teach_cpu

srun --mpi=pmi2 ./deadlock