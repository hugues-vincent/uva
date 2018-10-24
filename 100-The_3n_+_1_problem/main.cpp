#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>

#include "header/utils.h"
using namespace std;
int min(int t[], int n){
	int min = t[0];
	for (int i=1 ;i<n; i++)
		min = min < t[i] ? min : t[i];
	return min;
}
int max(int t[], int n){
	int max = t[0];
	for (int i=1 ;i<n; i++)
		max = max > t[i] ? max : t[i];
	return max;
}
int cycle(int i){
	int n = 0;
	if (i==0)
		return 0;
	n++;
	while(i != 1){
		n ++;
		i = i % 2 == 0 ? i/2 : 3*i+1;	
	}
	return n;
}
int cycle(int i, int t[]){
	int n = 0, i_0=i;
	if (i==0)
		return 0;
	while(i != 0){
		if (i < i_0){
			n += t[i];
			i = 0;
		}
		else{
			n ++;
			i = i % 2 == 0 ? i/2 : 3*i+1;	
		}
	}
	return n;
}
void print(int t[], int n){
	for(int i=0; i<n; i++){
		cout << i << ": " << t[i] << "\n";
	}
}
int main(int argc, char *argv[]){
	char *p;
	int i = 1, j = 110000, t[j], b[j];
	// n = strtol(argv[1], &p, 10);
    clock_t tStart2 = clock();
	for(int l=0; l<j; l++){
		b[l] = cycle(l) ;
	}
    printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);
    clock_t tStart = clock();
	t[0] = 0; 
	t[1] = 1; 
	for(int l=2; l<j; l++){
		t[l] = cycle(l, t);
	}
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	// cout << cycle(1);
	return 0;
}

