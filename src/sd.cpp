#include <iostream>
#include <vector>
#include <gsl/gsl_statistics.h>

int main() {
    std::vector<double> data;

    double x;
    while(std::cin >> x){
        data.push_back(x);
    }

    double sd = gsl_stats_sd(&data[0], 1, data.size());

    std::cout << sd << std::endl;

    return 0;
}
