#include <iostream>
using namespace std;

int main() {
    int hist[10000];
    for(int i=0;i<10000;i++){
        hist[i] = 0;
    }

    int range = 10;

    double x;
    while(cin >> x){
        hist[int(x*10) + 10 - int(x*10)%10]++;
    }

    for(int i=0;i<10000;i++){
        if(hist[i] > 0){
            cout << double(i)/10 << " " << hist[i] << endl;
        }
    }
}
