#include <iostream>
#include <algorithm>
#include <vector>
#include <gsl/gsl_histogram.h>
#include <cmath>

int main() {
    std::vector<double> data;

    double x;
    while(std::cin >> x) {
        data.push_back(x);
    }

    int n = 1 + log2(data.size());
    gsl_histogram *h = gsl_histogram_alloc(n);
    gsl_histogram_set_ranges_uniform(
            h,
            *std::min_element(data.begin(), data.end()),
            *std::max_element(data.begin(), data.end()));

    for(auto x : data) {
        gsl_histogram_increment(h, x);
    }

    gsl_histogram_fprintf(stdout, h, "%f", "%f");


    gsl_histogram_free(h);
}
