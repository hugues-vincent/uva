#include <iostream>

using namespace std;

int main() {
    int duration, n, m;
    double loans[101];
    double down_payment, initial_loan, depreciation, loan, car, monthly_payment;
    while(scanf("%d %lf %lf %d", &duration, &down_payment, &initial_loan, &n) != EOF && duration >= 0){
        for (int i = 0; i < 101; ++i)
            loans[i] = -1;
        while(n--)
            if(scanf("%d %lf", &m, &depreciation)){ loans[m] = depreciation;}

        depreciation = loans[0];
        loan = initial_loan;
        monthly_payment = initial_loan/duration;
        car = (initial_loan + down_payment) * (1 - loans[0]);
        
        int i = 0;
        while(i < duration && loan >= car) 
        {
            i++;
            if(loans[i] > 0) depreciation = loans[i];  
            car *= (1 - depreciation);
            loan -= monthly_payment;
        }
        printf("%d month", i); 
        if(i != 1) printf("s");
        printf("\n");
    }

    return 0;
}