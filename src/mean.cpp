#include <iostream>
#include <vector>
#include <gsl/gsl_statistics.h>

int main() {
    std::vector<double> data;

    double x;
    while(std::cin >> x){
        data.push_back(x);
    }

    double mean = gsl_stats_mean(&data[0], 1, data.size());

    std::cout << mean << std::endl;

    return 0;
}
