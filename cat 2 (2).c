// SIMPLE C PROGRAM HOUR-WORKED
/*
Name:Alex Mwangi Mwihia
Reg No:CT100/G/26203/25
Description:Program to compute gross pay, taxes and net [pay
*/
#include <stdio.h>

int main() {
    float hours_worked, hourly_wage;
    float gross_pay, taxes, net_pay;
    float overtime_hours;

    // Get user input
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours_worked);

    printf("Enter hourly wage: ");
    scanf("%f", &hourly_wage);

    // Calculate gross pay
    if (hours_worked > 40) {
        overtime_hours = hours_worked - 40;
        gross_pay = (40 * hourly_wage) + (overtime_hours * hourly_wage * 1.5);
    } else {
        gross_pay = hours_worked * hourly_wage;
    }

    // Calculate taxes
    if (gross_pay <= 600) {
        taxes = gross_pay * 0.15;
    } else {
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);
    }

    // Calculate net pay
    net_pay = gross_pay - taxes;

    // Display results
    printf("\n----- PAY SUMMARY -----\n");
    printf("Gross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", net_pay);

    return 0;
}
