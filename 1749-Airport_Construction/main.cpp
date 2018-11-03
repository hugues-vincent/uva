#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	int x;
	int y;
}  point;

typedef struct
{
  point p1, p2;
  // int i1, i2;
  double distance;
} segment;

void swap(point &p1, point &p2) {
    point tmp = p1;
    p1 = p2;
    p2 = tmp;
}
bool are_points_equal (const point &i,const point &j) { 
    return (i.x == j.x && i.y == j.y); 
}
bool segment_compare (segment i,segment j) { return (i.distance > j.distance); }
double distance(point p1, point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) 
		+ pow(p1.y - p2.y, 2));
}

bool is_segment_inside(const segment seg, std::vector<point> points){
    double alpha, beta, alpha1, beta1;
    double p1d1,p2d1, p2d2, p2d3;
    double dx1, dx2;
    int nb_points = points.size();
    point p1, p2, sp1, sp2;

    alpha = (seg.p1.x - seg.p2.x) == 0 ? 3*pow(10, 6) : (double)(seg.p1.y - seg.p2.y) / (seg.p1.x - seg.p2.x);
    beta = seg.p1.y - alpha * seg.p1.x;
    for (int i = 0; i < nb_points; ++i)
    {
        p1 = points[i];
        p2 = points[(i + 1) % nb_points];
        if(!are_points_equal(p1, seg.p1) && !are_points_equal(p2, seg.p2)) {
            p1d1 = p1.y - (alpha * p1.x + beta);
            p2d1 = p2.y - (alpha * p2.x + beta);
            if(p1d1 * p2d1 < 0){
                if (p2d1 < 0) 
                    swap(p1, p2);

                dx1 = p1.x - seg.p1.x;
                dx2 = p1.x - seg.p2.x;
                sp1 = abs(dx1) < abs(dx2) ? seg.p1 : seg.p2; 
                sp2 = abs(dx1) < abs(dx2) ? seg.p2 : seg.p1; 

                alpha1 = (sp1.x - p1.x) == 0 ? 3*pow(10, 6) : (double)(sp1.y - p1.y) / (sp1.x - p1.x);
                beta1 = p1.y - alpha1 * p1.x;
                p2d2 = p2.y - (alpha1 * p2.x + beta1);

                alpha1 = (sp2.x - p1.x) == 0 ? 3*pow(10, 6) : (double)(sp2.y - p1.y) / (sp2.x - p1.x);
                beta1 = p1.y - alpha1 * p1.x;
                p2d3 = p2.y - (alpha1 * p2.x + beta1);
        
                if((dx1*dx2 > 0 && p2d2 < 0 && p2d3 > 0) || (dx1*dx2 < 0 && p2d2 > 0 && p2d3 > 0)){
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n, x, y;
    point p;
    segment s;
    bool finded;
    std::vector<point> points;
    std::vector<segment> segments;

    while (scanf("%d", &n) != EOF) {
        finded = false;
        points.clear();
        segments.clear();
        for (int i=0 ; i<n ; i++){
            if (scanf("%d %d", &x, &y) == 2) {
                p.x = x;
                p.y = y;
                points.push_back(p);
            }
        }
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                s.p1 = points[i];
                s.p2 = points[j];
                s.distance = distance(points[i], points[j]);
                segments.push_back(s);
                // printf("%d %d\n", i, j);
            }
        }
        sort(segments.begin(), segments.end(), segment_compare);
        for (int i = 0; i < segments.size(); ++i)
        {
            // if (segments[i].p1.x == 40 && segments[i].p1.y == 0){
            printf("%d ", i);
            cout << segments[i].p1.x << " " << segments[i].p1.y << " " << segments[i].p2.x << " " << segments[i].p2.y << " ";
            cout << is_segment_inside(segments[i], points); 
            cout << " " << segments[i].distance << endl;
            // }
        }
        // int foo = 2;
        // cout << segments[foo].p1.x << " " << segments[foo].p1.y << " " << segments[foo].p2.x << " " << segments[foo].p2.y << " " << "\n\n";
        // cout << is_segment_inside(segments[foo], points) << " " << segments[foo].distance << endl;
        // int i = 0;
        // while (!finded && i < segments.size())
        // {
        //     finded = is_segment_inside(segments[i], segments);
        //     i++;
        // }
        printf("\n");
    }
    return 0;
}
