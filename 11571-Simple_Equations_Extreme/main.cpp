#include <iostream>
#include <cmath>
using namespace std;

#define EPS 1e-12



bool equal(long double x, long double y) { return abs(x - y) < EPS; }

bool is_solution(long double x, long double y, long double z, long long C) {
  if (x != y && z != x && z != y && equal(x*x + y*y + z*z, C)){
    printf("%0.Lf %0.Lf %0.Lf\n", x+EPS, y+EPS, z+EPS);
    return true;
  }
  return false;
}

int main() {
  int N;
  long long A, B, C;
  long double x, y, z;
  long double delta;
  if(scanf("%d", &N)){};
  while(N--)
  {
    bool sol = false;
    if(scanf("%llu %llu %llu", &A, &B, &C) != EOF) {};
    int x_max = B < (int)floor(sqrtl(C)) ? B : (int)floor(sqrtl(C)), y_max;
    for (x = -x_max; x <= x_max && !sol; x++){
      if (x != 0 && (delta = (A - x) * (A - x) - 4.*(long double)B/x) >= 0) {
        y = ((A - x) - sqrtl(delta)) / 2;
        z = A - x - y;
        if((sol = is_solution(x, y, z, C))) break;
      }
    } 
    if(!sol) printf("No solution.\n");
  }
  return 0;
}

