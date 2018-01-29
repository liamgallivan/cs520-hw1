/*
  Author: Liam Gallivan
  Description: takes user input for use in computing Simpson's Rule for a given function. Compares to output from trapezoidal rule program
  Created: 1/27/18

  Compile: gcc -g -Wall -o simpson simpson.c
  Run: ./simpson
 */

#include <stdio.h>
/*
  File: trap.c
  Contains: 
    f(double x): returns the result of f(x) = x^2 + 1;
    Trap(double a, double b, int n, double h): Returns area using trapezoidal rule as algortithm and f() as function
 */
#include "trap.c"

/*
  Function: Simpson
  Input: 
    a and b: left and right endpoints double;
    n: EVEN int number of intervals;
    h: length of intervals, double;
  Output: total_area under graph computed by Simpson's rule
 */
double Simpson(double a, double b, int n, double h)
{
  double total_area = 0.0;
  double interval_area;

  total_area = f(a) + f(b);
  for (int i = 1; i < n; i++)
  {
    interval_area = f(a + i*h);
    if (i % 2 == 0)
    {
      interval_area *= 2;
    } else
    {
      interval_area *= 4;
    }

    total_area += interval_area;
  }

  total_area *= (h / 3);
  return total_area;
}

/*
  Main Function
  User input:
    a and b: double endpoint positions
    n: EVEN number of intervals
  Prints prompts and results of Trapezoidal and Simpson Rule calculations
 */
int main()
{
  double a; double b; double h;
  double areaTrap; double areaSimpson;
  int n;

  printf("Enter following variables:\nLeft endpoint:  ");
  scanf("%lf", &a);
  printf("Right endpoint:  ");
  scanf("%lf", &b);
  printf("Number of sub-intervals:  ");
  scanf("%d", &n);
  while (n % 2 != 0)
  {
    printf("Number of sub-intervals must be even. Please enter an even integer:  ");
    scanf("%d", &n);
  }

  h = (b-a)/n;

  areaTrap = Trap(a, b, n, h);
  areaSimpson = Simpson(a, b, n, h);
  printf("Result of Trapezoidal rule is: %lf.\nResult of Simpson Rule is: %lf.\n", areaTrap, areaSimpson);
  printf("Difference between two results(Trap Rule - Simpson Rule): %lf.", areaTrap - areaSimpson);

  return 0;
}
