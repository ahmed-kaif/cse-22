#include <iostream>
#include <cmath>
#include <functional>

// Define the Ramanujan iterative function
double ramanujanMethod(std::function<double(double)> f, 
                       std::function<double(double)> df, 
                       double initialGuess, 
                       double tolerance, 
                       int maxIterations) {
    double x = initialGuess; // Start with the initial guess
    std::cout << "Iteration\tApproximation\tf(x)\n"; // Header for output
    for (int i = 0; i < maxIterations; ++i) {
        double fx = f(x);
        double dfx = df(x);

        // Print the current iteration results
        std::cout << i + 1 << "\t\t" << x << "\t\t" << fx << "\n";

        if (fabs(fx) < tolerance) {
            std::cout << "Root found after " << i + 1 << " iterations." << std::endl;
            return x; // Found a root
        }

        if (dfx == 0) {
            std::cerr << "Derivative is zero. Cannot proceed." << std::endl;
            return NAN; // Handle division by zero
        }

        // Ramanujan iteration formula
        double correction = -2 * fx * dfx / (2 * dfx * dfx - fx * f(x + fx / dfx));
        x += correction;
    }
    std::cerr << "Max iterations reached. No root found." << std::endl;
    return NAN; // Root not found
}

int main() {
    // Define the function and its derivative
    auto f = [](double x) { return x * x * x - x - 1; }; // Example: x^3 - x - 1
    auto df = [](double x) { return 3 * x * x - 1; };     // Derivative: 3x^2 - 1

    double initialGuess = 1.0;    // Initial guess close to the smallest root
    double tolerance = 1e-6;      // Tolerance for convergence
    int maxIterations = 100;      // Maximum number of iterations

    double root = ramanujanMethod(f, df, initialGuess, tolerance, maxIterations);

    if (!std::isnan(root)) {
        std::cout << "Smallest estimated root: " << root << std::endl;
    } else {
        std::cout << "Failed to find a root." << std::endl;
    }

    return 0;
}
