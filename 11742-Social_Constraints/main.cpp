#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int n) { int res = 1; for(int i=1; i<n+1 ; i++) res*=i; return res;}

bool is_position_valid(int a, int b, int c, int seat[], int n) {
  bool is_passed = false;
  int cpt = 0;
  for (int i = 0; i < n; ++i)
  {
    if(seat[i] == a || seat[i] == b) is_passed = !is_passed;
    if(is_passed) cpt++;
  }
  return ((c > 0 && cpt <= c) || (c < 0 && cpt >= -1*c));
}
int main() {
  int n, m, seat[] = {0, 1 , 2, 3, 4, 5, 6, 7}, cpt, constraint[20][3];
  bool is_valid;
  while(scanf("%d %d", &n, &m) != EOF && (m != 0 || n != 0)) {
    if (m == 0) {
      printf("%d\n", factorial(n));
      continue;
    }
    for (int i = 0; i < m ; ++i)
      if(scanf("%d %d %d", &constraint[i][0], &constraint[i][1], &constraint[i][2])) {};
    cpt = 0;
    do {
      is_valid = true;
      for (int i = 0; i < m && is_valid; ++i)
      {
        is_valid &= is_position_valid(constraint[i][0], constraint[i][1], constraint[i][2], seat, n);
      }
      if(is_valid) cpt++;
    } while (next_permutation(seat, seat + n));
    printf("%d\n", cpt);
  }
  return 0;
}