#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

#define EPS 1e-7
using namespace std;
typedef pair<double, double> p2f;

int main() {
    int n, l, w, p, d, cpt;
    vector<p2f> sprinklers;
    double covered;

    while(scanf("%d %d %d", &n, &l, &w) != EOF ) {
        sprinklers.clear();
        // transform the circle into segment
        // in oder to end up with an interval covering problem
        // remove circles that are strictly contained in the strip of grass  
        for (int i = 0; i < n; ++i)
        {
            if(scanf("%d %d", &p, &d)){}
            if (2.0 * d < w) continue;
            double r = sqrt((double)d*d - (double)w*w/4.);
            if(p - r <= l && p + r >= 0) {
                sprinklers.push_back({p - r, p + r});
            }
        }
        sort(sprinklers.begin(), sprinklers.end());
        // for each interval [x, y], compare [x, y] with [0, covered] ; their are 4 cases:
        // 1 - covered < x => interupted  <=> return -1
        // 2 - y < covered => [0, covered] contains [x, y], thus we must not count it <=> continue
        // 3 - their is [a, b] such that a < covered, b > covered, y < b => jump to [a, b] 
        //          without counting [x, y]
        // 4 - count [x, y]
        // if covered >= l => break the loop
        cpt = 0;
        covered = 0;
        for (int i = 0; i < sprinklers.size(); ++i)
        {
            if (covered + EPS >= l) break;
            if (covered >= sprinklers[i].second + EPS) continue;
            if (covered < sprinklers[i].first - EPS) {cpt = -1; break;}
            int j = i , u = i;
            while (j < sprinklers.size() && sprinklers[j].first - EPS <= covered) {
                if(sprinklers[j].second > sprinklers[u].second) u = j;
                j++;
            }
            covered = sprinklers[u].second;
            i = u;
            cpt++;
        }
        printf("%d\n", covered + EPS >= l ? cpt : -1);
    }
    return 0;
}