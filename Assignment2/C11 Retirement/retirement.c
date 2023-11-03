#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info
{
    int months;
    double contribution, rate_of_return;
} retire_info;

retire_info working = {489, 1000, 0.045 / 12};
retire_info retired = {384, -4000, 0.01 / 12};

void calculate_balance(double *savings, double rate, double cash_flow, int months, int *age)
{
    while (months)
    {
        printf("Age %3d month %2d you have $%.2lf\n", *age / 12, *age % 12, *savings);
        *savings = *savings + *savings * rate + cash_flow;
        months--;
        (*age)++;
    }
}

void retirement(int startAge,        // in months 以月为单位
                double initial,      // initial savings in dollars 初始存款
                retire_info working, // info about working		 关于工作信息
                retire_info retired) // info about being retired 关于退休信息
{
    calculate_balance(&initial, working.rate_of_return, working.contribution, working.months, &startAge);
    calculate_balance(&initial, retired.rate_of_return, retired.contribution, retired.months, &startAge);
}

int main(void)
{
    int startAge = 327;
    double initial = 21345;
    retirement(startAge, initial, working, retired);
    system("pause");
    return EXIT_SUCCESS;
}