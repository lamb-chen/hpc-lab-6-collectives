#!/bin/bash
#SBATCH --job-name=skele
#SBATCH --account=COMS033964
#SBATCH --nodes=2
#SBATCH --time=00:15:00
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --output=skele-job-output.out
#SBATCH --partition=teach_cpu

srun --mpi=pmi2 ./skeleton2-simple2d