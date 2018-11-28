#include <iostream>

using namespace std;

int day[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int year_length(int y) { return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0) ? 366 : 365; }
int month_length(int m, int y) {
    if (m == 1) return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0) ? 29 : 28;
    return day[m];
}
int add_day(int &d, int &m, int &y){
    d = (d + 1) % month_length(m, y);
    if (d == 0) {
        m = (m + 1) % 12;
        if (m == 0) y++;
    }
    return 1;
}
int main() {
    int N, d, m, y;
    int m_len, y_len;
    while(scanf("%d %d %d %d", &N, &d, &m, &y) != EOF && N != 0 && d != 0 && m != 0 && y != 0) {
        d--; m--;
        while( N > 0 && (m != 0 || d != 0)) N -= add_day(d, m, y);
        y_len = year_length(y);
        while(N >= y_len) {
            y++;
            N -= y_len;
            y_len = year_length(y);
        }
        while(N > 0) N -= add_day(d, m, y);
        printf("%d %d %d\n", d + 1, m + 1, y);
    }
    return 0;
}