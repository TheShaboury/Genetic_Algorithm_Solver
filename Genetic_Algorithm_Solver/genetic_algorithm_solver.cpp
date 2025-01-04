#include <iostream>
#include <math.h>
#include <random>
#include <vector>
#include <algorithm>

// Structure to represent a solution in the genetic algorithm
struct Solution
{
    double rank, x, y, z;
    
    // Fitness function to evaluate the quality of the solution
    void fitness()
    {
        double ans = ((3 * x) + (5 * y) - std::pow(z, 200)) - 12;
        
        // Assign rank based on how close the solution is to zero
        rank = (ans == 0) ? 9999 : std::abs(1 / ans);
    }
};

int main()
{
    // Create a random number generator
    std::random_device device;
    std::uniform_real_distribution<double> unif(-100, 100);
    
    // Vector to store all solutions
    std::vector<Solution> solutions;

    // Generate initial population
    const int NUM = 100000;
    for (int i = 0; i < NUM; i++)
        solutions.push_back(Solution{
            0,
            unif(device),
            unif(device),
            unif(device)
        });

    // Main genetic algorithm loop
    while (true)
    {
        // Evaluate fitness for all solutions
        for (auto& s : solutions) s.fitness();

        // Sort solutions by rank (descending order)
        std::sort(solutions.begin(), solutions.end(),
            [](const auto& lhs, const auto& rhs) {
                return lhs.rank > rhs.rank;
            });

        // Print top 10 solutions
        std::for_each(
            solutions.begin(),
            solutions.begin() + 10, [](const auto& s) {
                std::cout << std::fixed
                    << "Rank " << static_cast<int>(s.rank)
                    << "\n x:" << s.x << " y:" << s.y << " z:" << s.z
                    << " \n";
            });

        // Select top solutions for next generation
        const int SAMPLE_SIZE = 1000;
        std::vector<Solution> sample;
        std::copy(
            solutions.begin(),
            solutions.begin() + SAMPLE_SIZE,
            std::back_inserter(sample)
        );
        solutions.clear();

        // Mutate the selected solutions
        std::uniform_real_distribution<double> m(0.99, 1.01);
        std::for_each(sample.begin(), sample.end(), [&](auto& s) {
            s.x *= m(device);
            s.y *= m(device);
            s.z *= m(device);
        });

        // Perform crossover to create new solutions
        std::uniform_int_distribution<int> cross(0, SAMPLE_SIZE - 1);
        for (int i = 0; i < NUM; i++)
        {
            solutions.push_back(Solution{
                0,
                sample[cross(device)].x,
                sample[cross(device)].y,
                sample[cross(device)].z,
            });
        }
    }
}

