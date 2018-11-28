#include <iostream>

using namespace std;

int main(){
    int K, N, M, x, y;
    while(scanf("%d %d %d", &K, &N, &M) != EOF){
        while(K--) {
            if(scanf("%d %d", &x, &y)){}
            if(x - N == 0 || y - M == 0) printf("divisa\n");
            else if( x - N > 0 && y - M > 0) printf("NE\n");
            else if( x - N > 0 && y - M < 0) printf("SE\n");
            else if( x - N < 0 && y - M > 0) printf("NO\n");
            else  printf("SO\n");

        }
    }
    return 0;
}