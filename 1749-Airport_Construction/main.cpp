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
  int i1, i2;
  double distance;
} segment;

bool segment_compare (segment i,segment j) { return (i.distance > j.distance); }
double distance(point p1, point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) 
		+ pow(p1.y - p2.y, 2));
}
int main()
{
    int n, x, y;
    point p;
    segment s;
    std::vector<point> points;
    std::vector<segment> segments;

    while (scanf("%d", &n) != EOF) {
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
                s.i1 = i;
                s.i2 = j;
                s.distance = distance(points[i], points[j]);
                segments.push_back(s);
            }
        }
        sort(segments.begin(), segments.end(), segment_compare);
        for (int i = 0; i < segments.size(); ++i)
        {
            printf("%f\n", segments[i].distance);
        }
        printf("%d \n", segments.size());
        printf("\n");
    }
    return 0;
}
// int main1(int argc, char *argv[]){
// 	// cout.precision(11);
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(0, 1000000);

// 	int n = 100000;
//     clock_t tStart = clock();
//     std::vector<point> v;
//     for(int i(0); i<n; i++)
//     {
//     	point p = {.x = dis(gen), .y =dis(gen)};
//     	v.push_back(p);    	
//     }

// 	// point s[7] = {
// 	// 	{.x = 0, .y = 20},
// 	// 	{.x = 40, .y = 0},
// 	// 	{.x = 40, .y = 20},
// 	// 	{.x = 70, .y = 50},
// 	// 	{.x = 50, .y = 70},
// 	// 	{.x = 30, .y = 50},
// 	// 	{.x = 0, .y= 50},
// 	// };
// 	double max_distance = -1, curr_distance;
// 	// cout << distance(s[0], s[1]);
// 	for (int i(0); i<n; i++)
// 	{
// 		for(int j(0); j<i; j++)
// 		{
// 			curr_distance = distance(v[i], v[j]);
// 			if (curr_distance > max_distance)
// 				max_distance = curr_distance;
// 				// cout<< v[i].x<<", "<<v[i].y<<endl;

// 		}
// 	}

// 	cout << max_distance << endl;
//     printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
// 	return 0;
// }

