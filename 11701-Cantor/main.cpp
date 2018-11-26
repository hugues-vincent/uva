#include <iostream>
#include <cmath>
#define EPS 1e-7

using namespace std;

int main(){
    double x, a, b;
    while(scanf("%lf", &x)) {
        a = 0; 
        b = 1e6;
        x *= 1e6;
        while(true) {
            if(fabs(x - a) < EPS || fabs(x - b) < EPS) {
                printf("MEMBER\n");
                break;
            }
            else if(x > a && x < a + (b - a)/3) {
                b = a + (b - a)/3;
            }
            else if(x < b && x > b - (b - a)/3) {
                a = b - (b - a)/3;
            }
            else {
                printf("NON-MEMBER\n");
                break;
            }
        }
    }
    return 0;
}