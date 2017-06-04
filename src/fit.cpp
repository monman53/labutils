#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    int n = 0;

    double sum_x    = 0;
    double sum_y    = 0;
    double sum_x2   = 0;
    double sum_xy   = 0;

    int counter = 0;

    double x, y;
    while(cin >> x >> y){

        if(x <= 2){
            continue;
        }

        n++;

        x = log(x);
        y = log(y);

        sum_x   += x;
        sum_y   += y;
        sum_x2  += x*x;
        sum_xy  += x*y;
    }

    cout << ((n*sum_xy - sum_x*sum_y)/(n*sum_x2 - sum_x*sum_x)) << endl;

    return 0;
}
