#include <iostream>
#include <set>

using namespace std;


void SieveOfAtkin(int limit, bool sieve[]) 
{ 
    for (int i = 0; i < limit; i++) 
        sieve[i] = false; 
    sieve[2] = true;
    sieve[3] = true;
    for (int x = 1; x * x < limit; x++) { 
        for (int y = 1; y * y < limit; y++) { 
            int n = (4 * x * x) + (y * y); 
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) 
                sieve[n] ^= true; 
            n = (3 * x * x) + (y * y); 
            if (n <= limit && n % 12 == 7) 
                sieve[n] ^= true; 
            n = (3 * x * x) - (y * y); 
            if (x > y && n <= limit && n % 12 == 11) 
                sieve[n] ^= true; 
        } 
    } 
    for (int r = 5; r * r < limit; r++) { 
        if (sieve[r]) { 
            for (int i = r * r; i < limit; i += r * r) 
                sieve[i] = false; 
        } 
    } 
  
} 
int main() {
    int c, a, b;
    bool sieve[1000000];
    SieveOfAtkin(1000000, sieve);
    while(scanf("%d", &c) != EOF && c != 0) {
        a = 1;
        while(a <= c/2 && (!sieve[a] || !sieve[c - a])) a ++;
        printf("%d = %d + %d\n", c, a, c - a);
    }
    return 0;
}