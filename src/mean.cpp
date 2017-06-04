#include <iostream>
using namespace std;

int main() {
    int n;
    double x;
    double sum = 0.0;

    while(cin >> x){
        sum += x;
        n++;
    }
    cout << (sum/n) << endl;

    return 0;
}
