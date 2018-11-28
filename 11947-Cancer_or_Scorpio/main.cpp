#include <iostream>

using namespace std;
// const 

const int day[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    threshold_day[] = {20, 19, 20, 20, 21, 21, 22, 21, 23, 23, 22, 22};

const char* zodiac[] = {"aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};

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

int main(){
    int n, d, m, y;
    if(scanf("%d", &n)){}
    n = 0;
    while(scanf("%2d%2d%4d", &m, &d, &y) != EOF) {
        n++;
        d--; m--;
        for (int i = 0; i < 280; ++i)
            add_day(d, m, y);
        printf("%d %02d/%02d/%d %s\n", n, m+1, d+1, y, zodiac[d >= threshold_day[m] ? m: m == 0 ? 11 : m-1]);
    }
    return 0;
}