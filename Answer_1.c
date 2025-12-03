/*
A bank wants to calculate the total repayment amount for a loan using a recursive
approach. The loan decreases each year after paying a fixed installment, and interest is applied
annually to the remaining loan. Design a recursive function calculateRepayment(loan, interestRate, years)
that prints the repayment schedule year by year in the format "Year X: Remaining loan = Y" and
calculates the total repayment for n years. Identify the base case (loan fully repaid or no years
remaining) and the recursive case (repayment for remaining years). Using this function, trace the
repayment for a loan of 100,000 at 5% yearly interest over 3 years, and explain how recursion
helps track the loan state across years. Extend the function logically to handle extra yearly
payments and discuss why recursion is suitable for such incremental calculations.
*/


#include <stdio.h>


int fixedInstallment = 30000;
int total_years = 3;


double calculateRepayment(double loan, double interestRate, int years)
{
    if (loan <= 0 || years <= 0)
    {
        return 0;
    }else
    {
        loan -= fixedInstallment;
        loan = loan * (1 + (interestRate / 100));
        printf("Year %d: Remaining loan %.2lf\n", total_years + 1 - years, loan);
        return calculateRepayment(loan, interestRate, years - 1 ) + fixedInstallment;
    }
    
    
}


int main()
{

    printf("%.2lf",calculateRepayment(100000, 5, 3));
    return 0;
}


/* 
Recursion works best for this program as we need to travel across the years to find the loan
and it makes the code more concise 
*/