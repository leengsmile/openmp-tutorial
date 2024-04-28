#include <omp.h>
#include <iostream>

int main(int argc, char** argv) {
    #pragma omp parallel
    {
        std::cout << "Hello, World.\n";
    }

    #pragma omp parallel num_threads(5)
    {
        std::cout << "limited threads.\n";
    }
    // omp_set_num_threads(4);
    #pragma omp parallel
    {
        std::cout << "explicitly set omp threads.\n";
    }
    
    return 0;
}