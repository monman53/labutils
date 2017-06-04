#include <iostream>
using namespace std;

int main() {
    int n = 0;
    double x;
    double sum = 0.0;

    while(cin >> x){
        sum += x;
        n++;
    }
    
    if(n==0){
        return 0;
    }

    cout << (sum/n) << endl;

    return 0;
}
