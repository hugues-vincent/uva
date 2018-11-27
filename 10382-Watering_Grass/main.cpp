#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<double, double> p2f;

bool union_(const p2f a, const p2f b, p2f &i) {
    // printf("%d ", (a.second - b.first < 0) ? 1: 0);
    if (a.second - b.first < 0 || b.second - a.first < 0 ) {return false;}
    i = { a.first <= b.first ? a.first : b.first, 
        a.second  <= b.second ? b.second : a.second };
    return true;
}
bool contains(const p2f a, p2f b){
    return b.first <= a.first && b.second >= a.second;
} 
int main() {
    int n, l, w, p, d, cpt;
    p2f sprinklers[10000], I, Ic, curr, next;
    bool is_uninterrupted;
    double w2;

    int N = 0;
    while(scanf("%d %d %d", &n, &l, &w) != EOF ) {
        w2 = (double)w*(double)w/4.;
        int i = 0, j = 0;
        while(i < n)
        {
            if(scanf("%d %d", &p, &d)){}
            i++;
            if (2.0 * d < w) continue;
            double r = sqrt((double)d*d - w2);
            sprinklers[j] = {p - r < 0 ? 0 : p - r, p + r > l ? l : p + r};
            j++;
        }
        sort(sprinklers, sprinklers + j, [](p2f a, p2f b) { return a.second > b.second; });
        stable_sort(sprinklers, sprinklers + j, [](p2f a, p2f b) { return a.first < b.first; });

        cpt = 0;
        is_uninterrupted = true;
        I = {0, 0};
        for (int k = 0; k < j && is_uninterrupted; ++k)
        {
            curr = sprinklers[k];
            if (k < j -1){
                next = sprinklers[k+1];
                if (union_(I, next, Ic) && contains(curr, Ic)) continue;
            }
            is_uninterrupted = union_(I, curr, I);
            cpt++;
            if(I.second >= l) break;
        }
        if (I.second < l || !is_uninterrupted) printf("%d\n", -1);
        else printf("%d\n", cpt);    
    }
    return 0;
}