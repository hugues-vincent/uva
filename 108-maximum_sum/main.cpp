#include <iostream>
#include <stdio.h>

using namespace std;

int max_subarray(int A[101]){
    int curr_sum = 0, best_sum = 0;
    int i = 0, k = 0;
    while (i + k < 101){
        curr_sum = curr_sum + A[i + k];
        if (curr_sum > best_sum){
            best_sum = curr_sum;
        }
        if (curr_sum < 0){
            i = i + k + 1;
            k = 0;
            curr_sum = 0;
        }
        else {
            k++;
        }
    }
    return best_sum;
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

    int best_sum = 0, curr_sum = 0, reduced[101], sum = 0;

    for(int start_row = 0 ; start_row < n; start_row++){
        for(int end_row = start_row ; end_row < n ; end_row++){
            for (int col = 0; col < n; col++){
                sum = 0;
                for (int row = start_row ; row <= end_row; row++)
                    sum += A[row][col];
                reduced[col] = sum;
            }
            // cout << start_row << " | " << end_row << endl; 
            // for (int a = 0; a < n; a++) cout << reduced[a] << " ";
            //     cout << endl;
            //     cout << endl;
            curr_sum = max_subarray(reduced);
            if(curr_sum > best_sum)
                best_sum = curr_sum;
        }
    }
    cout << best_sum << endl;
    return 0;
}
// int sum(int i0, int j0, int ni, int nj, int A[101][101]){
//     int sum = 0;
//     for(int i = 0 ; i<ni ; i++){
//         for(int j = 0 ; j<nj ; j++){
//             if(i + i0 < 101 && j + j0 < 101){
//                 sum += A[i + i0][j + j0];
//             }
//         }
//     }
//     return sum;
// }
    // for(int ni = 1 ; ni<=n ; ni++){
    //     for(int nj = 1 ; nj<=n ; nj++){
    //         for(int i = 0 ; i < n - ni + 1; i++){
    //             for(int j = 0 ; j < n - nj + 1 ; j++){
    //                 curr_sum = sum(i, j, ni, nj, A);
    //                 if(curr_sum > best_sum)
    //                     best_sum = curr_sum;
    //             }
    //         }
    //     }
    // }
