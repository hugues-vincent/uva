#include <iostream>

using namespace std;

int main() {
    int N;
    bool is_passed = false;
    while(scanf("%d", &N) != EOF && N!=0){
        if (is_passed){
            printf("\n");
        }
        is_passed = true;

        bool has_solution = false;
        for (int b = 1234; b <= 98765/N; ++b)
        {
            int a = b * N;
            int tmp, used = (b < 10000);
            tmp = a; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            tmp = b; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            if (used == (1 << 10) - 1){
                has_solution = true;
                printf("%05d / %05d = %d\n", a, b, N);
            }
        }
        if(!has_solution) printf("There are no solutions for %d.\n", N);
    }
    return 0;
}