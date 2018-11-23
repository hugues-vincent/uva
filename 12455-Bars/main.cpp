#include <iostream>

using namespace std;

int main() {
    int nb_case, X, p, bars[20], sum;
    if(scanf("%d" , &nb_case)){}
    while (nb_case --){
        if(scanf("%d %d", &X, &p)){};
        int tmp = p;
        while(tmp--) if(scanf("%d", &bars[tmp])){};
        for (int i = 0; i < (1 << p); ++i)
        {
            sum = 0;
            for (int j = 0; j < p; ++j) if (i & (1 << j)) sum += bars[j];   
            if (sum == X) break;
        }
        if(sum == X) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}