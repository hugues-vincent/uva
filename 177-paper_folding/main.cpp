#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
void display_dragon(int n, vector<int> dragon) {
    int min_x = 0, max_x = 0, min_y = 0, max_y = 0 , x = 0, y = 0;
    std::vector<char> v;
    // 0 right, 1 up, 2 left, 3 down 
    for (int i = 0 ; i < pow(2, n); i++) {

        if (dragon[i] == 0) {
            x++;
            max_x = max(max_x, x);
        }
        else if (dragon[i] == 2) {
            x--;
            min_x = min(min_x, x);
        }
        else if (dragon[i] == 1) {
            y++;
            max_y = max(max_y, y);
        }
        else {
            y--;
            min_y = max(min_y, y);
        }
    }
}
int main() {
    int nb_fold, n = 0;
    vector<int> dragon = {0}, inputs = {};
    while (scanf("%d", &nb_fold) != EOF && nb_fold != 0){
        inputs.push_back(nb_fold);
        n = max(n, nb_fold);
    }
    // 0 right, 1 up, 2 left, 3 down 
    for (int i=0 ; i < n; i++) {
        for (int j = dragon.size() - 1 ; j >= 0 ; j--) {
            dragon.push_back((dragon[j] + 1) % 4);
        }
    }
    for(int input : inputs) {
        display_dragon(input, dragon);
    }
    // for(int el : dragon) printf("%d ", el);
    
    return 0;
}


// #include <stdio.h> 
// #include <map>
// #include <set>
// #include <algorithm>
// using namespace std;
// map<int, set< pair<int, int> > > P;
// void build(int n) {
//     int A[1<<15];
//     // 0 up, 1 down, 2 left, 3 right
//     int trans[] = {2, 3, 1, 0};
//     int m = 1;
//     A[0] = 3;
//     for(int i = 1; i <= n; i++) {
//         for(int j = m - 1, k = m; j >= 0; j--, k++)
//             A[k] = trans[A[j]];
//         m = m << 1;
//     }
//     int x = -1, y = 0, px = 0, py = 0;
//     P.clear();
//     for(int i = 0; i < m; i++) {
//         if(A[i] == 0)       x = px<<1, y = py;
//         else if(A[i] == 1)  x = px<<1, y = py - 1;
//         else if(A[i] == 2)  x = (px<<1)-1, y = py;
//         else                x = (px<<1)+1, y = py;
//         //printf("%d %d %d - %d %d\n", px, py, A[i], x, y);
//         if(A[i] == 0) {
//             P[y].insert(make_pair(x, 0));
//         } else if(A[i] == 1) {
//             P[y].insert(make_pair(x, 1));
//         } else if(A[i] == 2) {
//             P[y].insert(make_pair(x, 2));
//         } else {
//             P[y].insert(make_pair(x, 3));
//         }
//         if(A[i] == 0)       py++;
//         else if(A[i] == 1)  py--;
//         else if(A[i] == 2)  px--;
//         else                px++;
//     }
// }
// int main() {
//     for(int n; scanf("%d", &n) == 1 && n; ) {
//         build(n);
//         int mxy = -0x3f3f3f3f, mnx = 0x3f3f3f3f;
//         for(map<int, set< pair<int, int> > >::iterator it = P.begin();
//         it != P.end(); it++) {
//             mxy = max(mxy, it->first);
//             for(set< pair<int, int> >::iterator jt = it->second.begin();
//                 jt != it->second.end(); jt++) {
//                 mnx = min(mnx, jt->first);
//             }
//         }
//         for(map<int, set< pair<int, int> > >::reverse_iterator it = P.rbegin();
//         it != P.rend(); it++) {
//             int i = mnx;
//             for(set< pair<int, int> >::iterator jt = it->second.begin();
//                 jt != it->second.end(); jt++) {
//                 while(i < jt->first)    putchar(' '), i++;
//                 i++;
//                 if(jt->second == 0 || jt->second == 1)
//                     putchar('|');
//                 else
//                     putchar('_');
//             }
//             puts("");
//         }
//         //printf("%d %d\n", mxy, mnx);
//         puts("^");
//     }
//     return 0;
// }