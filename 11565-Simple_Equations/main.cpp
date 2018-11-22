#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, A, B, C;
  if(scanf("%d", &N)){};
  for (int i = 0; i < N; ++i)
  {
    bool sol = false; 
    int x, y, z;
    if(scanf("%d %d %d", &A, &B, &C) != EOF) {};
    for (x = -22; x <= 22 && !sol; x++) if (x * x <= C)
      for (y = -100; y <= 100 && !sol; y++) if (y != x && x * x + y * y <= C)
        for (z = -100; z <= 100 && !sol; z++) 
          if (z != x && z != y && x + y + z == A && x * y * z == B && x * x + y * y + z * z == C)
          {
            printf("%d %d %d\n", x, y, z);
            sol = true; 
          }
    if(!sol) printf("No solution.\n");
  }
  return 0;
}