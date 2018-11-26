#include <iostream>
#include <cmath>
#define EPS 1e-7

using namespace std;
int p, q, r, s, t, u;
double x, f_x, a, b;

double f(double x) { return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u; }
double df(double x) { return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x; }
void bisection() {
    if(f(0.) * f(1.) > 0) printf("No solution\n");
    else if (fabs(f(0)) < EPS) printf("%0.4f\n", 0.);
    else if (fabs(f(1)) < EPS) printf("%0.4f\n", 1.);
    else {
        if (f(0) > 0) {a = 0; b = 1; }
        else {a = 1; b = 0; }
        x = 0.5;
        f_x = f(x);
        while (fabs(f_x) > EPS) {
            if (f_x > 0) a = x;
            else b = x;
            x = (a + b) / 2;
            f_x = f(x);
        }
        printf("%.4f\n", x);
    }
}
 
void newton() {
    if (f(0) * f(1) > 0) { printf("No solution\n");  return; }
    x = 0.5;
    while (fabs(f(x)) > EPS) {
        x -= f(x) / df(x);
    }
    printf("%0.4f\n", abs(x));
}
int main() {
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        newton();
    }
    return 0;
}