#include <iostream>
#include <stdio.h>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}
int max_subarray(int A[101]){
    int max_ending_here = 0, max_so_far = 0;
    for (int i = 0 ; i < 101 ; i++){
        max_ending_here = max(A[i], A[i] + max_ending_here);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
int main()
{
    int n, A[101][101];

    if(scanf("%d", &n)==1){}
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(scanf("%d", &A[i][j]) == 1){};
        }
    }

    int cum_sum[101][101];
    for(int col = 0 ; col<n ; col++){
        cum_sum[0][col] = A[0][col];
        for(int row = 1 ; row<n ; row++){
            cum_sum[row][col] = A[row][col] + cum_sum[row - 1][col];
        }
    }
    int best_sum = 0, curr_sum = 0, reduced[101], sum = 0;

    for(int start_row = 0 ; start_row < n; start_row++){
        for(int end_row = start_row ; end_row < n ; end_row++){
            for (int col = 0; col < n; col++){
                reduced[col] = start_row == 0 ?
                    cum_sum[start_row][col] :
                    cum_sum[end_row][col] - cum_sum[start_row - 1][col];
            }
            curr_sum = max_subarray(reduced);
            if(curr_sum > best_sum)
                best_sum = curr_sum;
        }
    }
    cout << best_sum << endl;
    return 0;
}
