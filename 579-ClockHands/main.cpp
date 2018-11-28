#include <iostream>
#include <cmath>

using namespace std;
const double h_step = 360./12./60., m_step = 360./60.;

int main() {
    int h, m;
    double angle;
    while(scanf("%d:%d", &h, &m) != EOF && (h != 0 || m != 0)){
        double angle = fabs(m * m_step - (h * 60 + m) * h_step);
        printf("%.3lf\n", angle > 180 ? 360 - angle : angle);
    }
    return 0;
}