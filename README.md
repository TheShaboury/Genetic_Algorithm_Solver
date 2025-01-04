# Genetic_Algorithm_Solver
This C++ project implements a genetic algorithm to find approximate solutions to a given equation.


## Description

This program uses a genetic algorithm approach to find approximate solutions to the given equation. It starts with a large population of random solutions and iteratively improves them through selection, mutation, and crossover operations.

### Key Features:

1. **Population Initialization**: Generates 100,000 random solutions within the range [-100, 100] for x, y, and z.
2. **Fitness Evaluation**: Calculates how close each solution is to satisfying the equation.
3. **Selection**: Sorts solutions based on their fitness and selects the top 1,000 for the next generation.
4. **Mutation**: Applies small random changes to the selected solutions.
5. **Crossover**: Creates new solutions by combining parameters from the selected solutions.
6. **Continuous Improvement**: Repeats the process indefinitely, constantly refining the solutions.

## How to Use

1. Compile the C++ file:
**g++ -std=c++11 genetic_algorithm_solver.cpp -o solver.**

2. Run the executable:
**./solver**

3. The program will continuously output the top 10 solutions it has found.

## Requirements

- C++11 compatible compiler
- Standard C++ libraries

## Notes

- The program runs indefinitely, continuously improving its solutions. You may need to manually terminate it once you're satisfied with the results.
- Due to the nature of genetic algorithms and the complexity of the equation, the program may not find an exact solution but will approach increasingly better approximations over time.

## Future Improvements

- Implement a termination condition based on a target fitness or maximum number of generations.
- Add command-line arguments for customizing parameters like population size, mutation rate, etc.
- Extend the program to solve different equations by making the fitness function configurable.

Feel free to contribute to this project by submitting pull requests or opening issues for suggestions and bug reports.
