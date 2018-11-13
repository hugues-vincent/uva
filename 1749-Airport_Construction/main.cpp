#include <iostream>
#include <iomanip> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	double x;
	double y;
}  point;

double max(const double a, const double b) {
    return a > b ? a : b;
}
double min(const double a, const double b) {
    return a < b ? a : b;
}

void swap(point &p1, point &p2) {
    point tmp = p1;
    p1 = p2;
    p2 = tmp;
}
double distance(point p1, point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}


void update_inf_or_supp_point(const point cp, const point p1, const point p2, const double alpha, point &p_inf, point &p_sup){
    double cp_pos = (cp.x + alpha * cp.y);
    if(cp_pos >= (p2.x + alpha * p2.y) && cp_pos < (p_sup.x + alpha * p_sup.y)){
        p_sup = cp;
    }
    else if (cp_pos <= (p1.x + alpha * p1.y) && cp_pos > (p_inf.x + alpha * p_inf.y)){
        p_inf = cp;
    }
}

void get_intersection_vector(const point &p1, const point &cp1,const bool &is_vertical_c, const bool &is_vertical, const double &alpha_c, const double &alpha, const double &beta_c, const double &beta , double &x, double &y){
    x = NAN;
    y = NAN;
    if (is_vertical){
        x = p1.x;
        y = alpha_c * x + beta_c;
    }
    else if (is_vertical_c){
        x = cp1.x;
        y = alpha * x + beta;
    }
    else if ((alpha_c - alpha) != 0) {
        x = (beta - beta_c) / (alpha_c - alpha);
        y = (alpha_c * beta - alpha * beta_c) / (alpha_c - alpha);
    }
}
std::vector<bool> find_polygon_orientation(const std::vector<point> points){
    std::vector<bool> orientation;
    point p1 = points[0],
        p2 = points[1],
        p_mid = {0.5 * (p1.x  + p2.x), 0.5 * (p1.y  + p2.y)};
    bool is_vertical;
    double alpha = -(p1.y - p2.y) / (p1.x - p2.x),
        beta = p_mid.y - alpha * p_mid.x;

    point cp1, cp2;
    double alpha_c, beta_c, theta_c, x, y;
    bool is_vertical_c;


    for (int i = 1; i < points.size(); ++i)
    {
        cp1 = points[i];
        cp2 = points[(i + 1) % points.size()];

        is_vertical_c = ((cp1.x - cp2.x) == 0);
        alpha_c = is_vertical_c ? 0 : (double)(cp1.y - cp2.y) / (cp1.x - cp2.x);
        beta_c = cp1.y - alpha_c * cp1.x;
        
        get_intersection_vector(p1, cp1, is_vertical_c, is_vertical, alpha_c, alpha, beta_c, beta, x, y);
        
        if (!isnan(x)){
            theta_c = (x - cp1.x) / (cp2.x - cp1.x);

        }
    }
    return orientation;
}
double prolong_and_find_longest_segment(const int i1, const int i2, const std::vector<point> points) {
    point p1 = points[i1], p2 = points[i2], p_inf, p_sup;

    // get alpha & beta of the current line
    double alpha, beta;
    bool is_vertical;
    is_vertical = ((p1.x - p2.x) == 0);
    alpha = is_vertical ? 0 : (double)(p1.y - p2.y) / (p1.x - p2.x);
    beta = p1.y - alpha * p1.x;
    if ((p2.x + p2.y * alpha) < (p1.x + p1.y * alpha))
        swap(p1, p2);
    p_sup = {INFINITY, alpha * INFINITY};
    p_inf = {-INFINITY, -alpha * INFINITY};

    // get intersection points between the current line and the polygon
    point cp1, cp2;
    std::vector<point> colinear_intersections;
    double alpha_c, beta_c, theta, theta_c, x, y;
    bool is_vertical_c;

    printf(" %d %d\n", i1, i2);
    for (int i = 0; i < points.size(); ++i)
    {
        cp1 = points[i];
        cp2 = points[(i + 1) % points.size()];
        
        // get alpha_c and beta_c 
        is_vertical_c = ((cp1.x - cp2.x) == 0);
        alpha_c = is_vertical_c ? 0 : (double)(cp1.y - cp2.y) / (cp1.x - cp2.x);
        beta_c = cp1.y - alpha_c * cp1.x;
        get_intersection_vector(p1, cp1, is_vertical_c, is_vertical, alpha_c, alpha, beta_c, beta, x, y);

        if (!isnan(x)){
            theta = (x - p1.x) / (p2.x - p1.x);
            theta_c = (x - cp1.x) / (cp2.x - cp1.x);
            // printf("x:%f y:%f\n", x, y);
            
            // normal cases
            if (theta_c > 0 && theta_c < 1) {
                // in semgent [p1, p2]
                if (theta > 0 && theta < 1) 
                    return 0;
                // out semgent [p1, p2]  
                else 
                    update_inf_or_supp_point({x, y}, p1, p2, alpha, p_inf, p_sup);
            }
            // limit cases
            else if (theta_c == theta_c*theta_c){
                int k = (x == cp1.x && y == cp1.y) ? i : (i + 1) % points.size();
                point bp = points[k == 0 ? points.size() -1 : k - 1], ap = points[(k + 1) % points.size()];

                double bpd = is_vertical ? bp.x - p1.x : bp.y - (alpha * bp.x + beta);
                double apd = is_vertical ? ap.x - p1.x : ap.y - (alpha * ap.x + beta);
                if (bpd * apd < 0){
                    if(theta > 0 && theta < 1) 
                        return 0;
                    else 
                        update_inf_or_supp_point({x, y}, p1, p2, alpha, p_inf, p_sup);
                }
                else if (bpd * apd == 0) {
                    colinear_intersections.push_back({x, y});
                    // if(theta >= 0 && theta <= 1) 
                    // else
                }
            }
        }
    }
    if((i1 - i2) > 1){
        cp1 = points[(i1 + 1) % points.size()];
        cp2 = points[(i2 + 1) % points.size()];
        double p1d1 = is_vertical ? cp1.x - p1.x : cp1.y - (alpha * cp1.x + beta),
            p2d1 = is_vertical ? cp2.x - p1.x : cp2.y - (alpha * cp2.x + beta);
        if(p1d1 * p2d1 > 0){
            return 0;
        }
    }
    // sort(intersections.begin(), intersections.end(), [p1](point a, point b){return ((a.x + a.y) < (b.x + b.y));});
    // for (int i = 0; i < intersections.size(); ++i)
    // {
    //     printf("%f %f\n", intersections[i].x, intersections[i].y);
    // }

    if (p_inf.x == INFINITY) p_inf = p1;
    if (p_sup.x == -INFINITY) p_sup = p2;
    return distance(p_inf, p_sup);
}
int main()
{
    int n;
    bool finded;
    std::vector<point> points;
    double longest_distance = 0, x, y;
    std::cout.precision(9);
    std::cout.setf(std::ios::fixed, std:: ios::floatfield);

    while (scanf("%d", &n) != EOF) {
        finded = false;
        points.clear();
        for (int i=0 ; i<n ; i++){
            if (scanf("%lf %lf", &x, &y) == 2) {
                points.push_back({x, y});
            }
        }

        prolong_and_find_longest_segment(4, 5, points);
        printf("\n");
        prolong_and_find_longest_segment(2, 3, points);
        printf("\n");
        prolong_and_find_longest_segment(1, 2, points);
        
        // for (int i = 0; i < points.size(); ++i)
        // {
        //     for (int j = i + 1; j < points.size(); ++j)
        //     {
        //         longest_distance =  max(prolong_and_find_longest_segment(i, j, points), longest_distance);
        //     }
        // }        

        // cout << longest_distance << endl;



        // for (int i = 0; i < points.size(); ++i)
        // {
        //     for (int j = i + 1; j < points.size(); ++j)
        //     {
        //         segments.push_back({
        //             points[i],
        //             points[j],
        //             i,
        //             j,
        //             distance(points[i], points[j])
        //         });
        //         // printf("%d %d\n", i, j);
        //     }
        // }
        // sort(segments.begin(), segments.end(), segment_compare);

        // int i = 0;
        // finded = false;
        // while (!finded && i < segments.size())
        // {
        //     finded = is_segment_inside(segments[i], points);
        //     i++;
        // }
        // std::cout.precision(9);
        // std::cout.setf( std::ios::fixed, std:: ios::floatfield );
        // cout << segments[i - 1].distance << endl;



        // printf("%d\n", segments.size() );
        // for (int i = 0; i < segments.size(); ++i)
        // {
        //     // cout << segments[i].p1.y << " " << endl;
        //     // printf("%d %d %d %d %d\n", segments[i].p1.x, segments[i].p1.y, segments[i].p2.x, segments[i].p2.y, is_segment_inside(segments[i], points));
        //     printf("%d %d %d %d %d\n", segments[i].p1.x, segments[i].p1.y, segments[i].p2.x, segments[i].p2.y, is_segment_inside(segments[i], points));
        // }
    }
    return 0;
}

typedef struct
{
  point p1, p2;
  int i1, i2;
  double distance;
} segment;

// bool segment_compare (segment i,segment j) { return (i.distance > j.distance); }
bool is_segment_inside(const segment seg, std::vector<point> points){
    double alpha, beta, alpha1, beta1;
    double p1d1,p2d1, p2d2, p2d3;
    double dx1, dx2;
    int nb_points = points.size();
    point p1, p2, sp1, sp2;
    bool is_vertical1, is_vertical2, is_vertical3; 

    is_vertical1 = ((seg.p1.x - seg.p2.x) == 0);
    alpha = is_vertical1 ? 0 : (double)(seg.p1.y - seg.p2.y) / (seg.p1.x - seg.p2.x);
    beta = seg.p1.y - alpha * seg.p1.x;
    for (int i = 0; i < nb_points; ++i)
    {
        p1 = points[i];
        p2 = points[(i + 1) % nb_points];
        if(i != seg.i1 && ((i + 1) % nb_points) != seg.i2) {
            p1d1 = is_vertical1 ? p1.x - seg.p1.x : p1.y - (alpha * p1.x + beta);
            p2d1 = is_vertical1 ? p2.x - seg.p1.x : p2.y - (alpha * p2.x + beta);
            if(p1d1 * p2d1 < 0){
                if (p2d1 < 0)
                    swap(p1, p2);

                dx1 = p1.x - seg.p1.x;
                dx2 = p1.x - seg.p2.x;
                sp1 = abs(dx1) < abs(dx2) ? seg.p1 : seg.p2; 
                sp2 = abs(dx1) < abs(dx2) ? seg.p2 : seg.p1; 

                is_vertical2 = ((sp1.x - p1.x) == 0);
                alpha1 = is_vertical2 ? p2.x - p1.x : (double)(sp1.y - p1.y) / (sp1.x - p1.x);
                beta1 = p1.y - alpha1 * p1.x;
                p2d2 = p2.y - (alpha1 * p2.x + beta1);

                is_vertical3 = ((sp2.x - p1.x) == 0);
                alpha1 = is_vertical3 ? p2.x - p1.x : (double)(sp2.y - p1.y) / (sp2.x - p1.x);
                beta1 = p1.y - alpha1 * p1.x;
                p2d3 = p2.y - (alpha1 * p2.x + beta1);
        
                if((dx1*dx2 > 0 && p2d2 < 0 && p2d3 > 0) || (dx1*dx2 < 0 && p2d2 > 0 && p2d3 > 0)){
                    return false;
                }
            }
        }
    }
    if(seg.i1 + 1 != seg.i2){
        p1 = points[(seg.i1 + 1) % points.size()];
        p2 = points[(seg.i2 + 1) % points.size()];
        p1d1 = is_vertical1 ? p1.x - seg.p1.x : p1.y - (alpha * p1.x + beta);
        p2d1 = is_vertical1 ? p2.x - seg.p1.x : p2.y - (alpha * p2.x + beta);
        if(p1d1 * p2d1 > 0){
            return false;
        }
    }
    return true;
}