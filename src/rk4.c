#include <stdio.h>

#define N 5

double f0(double *v) {
    return 0;
}

double f1(double *v) {
    return 0;
}

double f2(double *v) {
    return 0;
}

double f3(double *v) {
    return 0;
}

double f4(double *v) {
    return 0;
}


int main() {
    // functions
    double (*fs[N])(double *) = {f0, f1, f2, f3, f4};

    // values
    double v[N] = {0, 0, 0, 0, 0}, tmp[N];
    double k[4][N];
    double s[4] = {0, 0.5, 0.5, 1};

    // time variables
    double T    = 1.0;    // max time
    double dt   = 0.1;

    for(double t=0;t<T;t+=dt){
        // values output
        for(int i=0;i<N;i++){
            printf("%lf", v[i]);
            if(i != N-1) printf(", ");
        }
        printf("\n");

        // calculate k
        for(int i=0;i<4;i++){
            for(int j=0;j<N;j++){
                tmp[j] = v[j];
                if(i > 0) tmp[j] += dt*k[i-1][j]*s[i];
            }
            for(int j=0;j<N;j++){
                k[i][j] = (*fs[j])(tmp);
            }
        }

        // update values
        for(int i=0;i<N;i++){
            v[i] = v[i] + (k[0][i] + 2*k[1][i] + 2*k[2][i] + k[3][i])*dt/6.0;
        }
    }
    return 0;
}
