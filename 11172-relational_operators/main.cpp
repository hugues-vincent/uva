#include <iostream>

using namespace std;

int main(){
    int n, a, b;
    if(scanf("%d", &n)){}
    while(n--){
        if(scanf("%d %d", &a, &b)){}
        if(a == b) printf("=\n");
        else if(a < b) printf("<\n");
        else printf(">\n");
    }
    return 0;
}