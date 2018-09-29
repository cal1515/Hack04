/**
* Author: Cal Malone
*
* This program will be used to compute and display an amortization table
* for a 401(k) account, factoring in inflation, using command line arguments.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)   {

  if(argc !=6) {
    printf("Error: Not the correct number of command line arguments.\n") ;
    exit(1) ;
}

double initialBalance = atof(argv[1]) ;
double monthlyContribution = atof(argv[2]) ;
double averageRateOfReturn = atof(argv[3]) ;
double averageRateOfInflation = atof(argv[4]) ;
int years = atoi(argv[5]) ;

  if((monthlyContribution * 12) > 18500) {
    printf("Error: Illegal monthly contributions, exceeds $18,500 annual limit\n") ;
    exit(1) ;
  }

  if(averageRateOfReturn < 0 || averageRateOfReturn > 1) {
    printf("Error: Please enter a rate of return between 0 and 1. Example:\n For 9 percent, type 0.09\n") ;
    exit(1) ;
}
  if(averageRateOfInflation < 0 || averageRateOfInflation > 1) {
    printf("Error: Please enter a rate of inflation between 0 and 1. Example:\n For 2.1 percent, type 0.021\n") ;
    exit(1) ;
}

double currentBalance = initialBalance ;
double interest = (((1+averageRateOfReturn)/(1+averageRateOfInflation))-1) ;
double totalInterest = 0 ;

    printf("Month   Interest   Balance\n") ;
  for(int i=1 ; i <= years*12 ; i++) {
    double monthInterest = currentBalance * interest / 12 ;
    monthInterest = round(monthInterest * 100) / 100 ;
    currentBalance = currentBalance + monthInterest + monthlyContribution ;
    totalInterest = totalInterest + monthInterest ;
    printf("%3d $%10.2f $%10.2f\n", i, monthInterest, currentBalance) ;
}
    printf("Total Interest Earned: $%.2f\n", totalInterest) ;
    printf("Total Nest Egg: $%.2f\n", currentBalance) ;

  return 0 ;
}
