#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    char e[17];
    priority_queue<double> pq;
    int km, last_km, fuel_consumption, leak;
    double fuel;
    fuel = fuel_consumption = km = last_km = leak = 0;
    while (scanf("%d %s", &km, e) != EOF) {
        fuel += leak * (km - last_km) + fuel_consumption * (double)(km - last_km) / 100; 
        last_km = km;
        if (strcmp(e, "Fuel") == 0) { if(scanf("%s %d", e, &fuel_consumption)){} }
        else if(strcmp(e, "Leak") == 0) leak++;
        else if(strcmp(e, "Gas") == 0){
            if(scanf("%s", e)){}
            pq.push(fuel);
            fuel = 0;
        }
        else if(strcmp(e, "Mechanic") == 0) leak = 0;
        else if(strcmp(e, "Goal") == 0){
            pq.push(fuel);
            printf("%0.3f\n", pq.top());
            pq = priority_queue<double>();
            fuel = fuel_consumption = km = last_km = leak = 0;
        }
    }
    return 0;
}