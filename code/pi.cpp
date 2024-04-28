#include <omp.h>
#include <iostream>
#include <iomanip>
#include <chrono>

double f(double x) {
    return 1. / (1 + x*x);
}
double rough_pi(int n = 100'000'000) {

    double delta = 1.0 / static_cast<double>(n);
    double sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        double x = (i + 0.5) * delta;
        sum += f(x);
    }
    sum *= 4 * delta;
    return sum;
}

int main(int argc, char** argv) {
    
    const auto start(std::chrono::high_resolution_clock::now());
    double pi = rough_pi();
    const auto end(std::chrono::high_resolution_clock::now());
    const auto elapsed = (end - start) / std::chrono::milliseconds(1);
    auto a = std::chrono::milliseconds(elapsed).count();
    std::cout << "pi = " << std::setprecision(16) << pi 
              << " , elapsed: " << elapsed  << " ms" << std::endl;

}