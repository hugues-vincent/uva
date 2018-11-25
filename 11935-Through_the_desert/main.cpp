#include <iostream>
#include <queue>

using namespace std;
double max(double a, double b) { return a > b ? a : b; }
int main() {
    char e[17];
    int km, last_km, fuel_consumption, leak;
    double fuel, max_fuel;
    max_fuel = fuel = fuel_consumption = km = last_km = leak = 0;
    while (scanf("%d %s", &km, e) != EOF) {
        fuel += leak * (km - last_km) + fuel_consumption * (double)(km - last_km) / 100; 
        last_km = km;
        if (e[0] == 'F') { if(scanf("%s %d", e, &fuel_consumption)){} }
        else if(e[0] == 'L') leak++;
        else if(e[1] == 'a'){
            if(scanf("%s", e)){}
            max_fuel = max(max_fuel, fuel);
            fuel = 0;
        }
        else if(e[0] == 'M') leak = 0;
        else {
            printf("%0.3f\n", max( max_fuel, fuel));
            max_fuel = fuel = fuel_consumption = km = last_km = leak = 0;
        }
    }
    return 0;
}