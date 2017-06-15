#include <iostream>
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
        sum_x   += x;
        sum_y   += y;
        sum_x2  += x*x;
        sum_xy  += x*y;

        n++;
    }

    double a = ((n*sum_xy - sum_x*sum_y)/(n*sum_x2 - sum_x*sum_x));

    cout << a << endl;

    return 0;
}
