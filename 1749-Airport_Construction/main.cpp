#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <vector>
#include <random>

using namespace std;

typedef struct
{
	int x;
	int y;
}  point;

double distance(point p1, point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) 
		+ pow(p1.y - p2.y, 2));
}
int main()
{
    int stack[1];
    cout<<"ee" << endl;
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

