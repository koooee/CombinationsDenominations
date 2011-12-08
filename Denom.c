/*
Denom.c
Purpose:
  File contains functionality for denominations problem.  There is no need to compile this file it will be included in Main.c
Programmer: Nick Kolegraff
Date: 6/19/2011
*/

#include "Denom.h"

double input_ok(char *cinput)
{/* if the input is not ok I decided to kill the program since we can't really do anything */

  /* Before we do any thing serious, lets check the input */
  double input, min_denom, value, fvalue, max, diff;

  char *p = malloc(strlen(cinput) * sizeof(char));
  errno = 0;
  input = fabs(strtod(cinput, &p));
  max = pow(2.0, 40.0);

  if(strcmp(p, cinput) == 0)
    {
      printf("Invalid Input, expecting a decimal number\n");
      exit(EXIT_FAILURE);
    }

  if(errno == ERANGE)
    {
      printf("Overflow/Underflow would occur with input value\n");
      exit(EXIT_FAILURE);
    }

  if(input >= max)
    {
      printf("Value is too large, unexpected behavior would occur\n");
      exit(EXIT_FAILURE);
    }

  /* now lets make sure we have small enough denominations to make the number */
  min_denom = denoms[MAX_DENOMINATIONS - 1];
  value = input / min_denom;
  fvalue = floor(value);
  diff = value - fvalue;
  if(diff < .999 && diff > .001)
    {/* probably a better way around this, boolean comparison not the best with floating points */
      
      printf("Can't calculate for input value %s, denominations are not granular enough\n" ,cinput);
      exit(EXIT_FAILURE);
    }
  if(strlen(p) > 0)
    printf("You have this '%s' in your input...I'll ignore it for you\n",p);

  return input;
}

double combinations(double input)
{
  int i, j;
  double tcomb = 0.0; /*tcomb: total combinations */
  for(i = 0; i < MAX_DENOMINATIONS-2; i++)
    {/* subtract 2 since we are doing i+1 below...and the final i is taken care of in the return */
      double max_use = floor(input/denoms[i]);
      printf("%lf\n", max_use);
      for(j = 0; j <= max_use; j++)
	{
	  /* 
	     if you use j from the current denomination (i) to recreate the input, the total combinations
	     for the i'th and i'th + 1 denominations will be the summation of the
	     leftovers for the (i+1) denomination. Iterate over all the i's gives you
	     the total combinations for all of the denominations.
	   */
	  tcomb += floor((input - (j * denoms[i])) / denoms[i+1]);
	}
    }
  return ++tcomb; /* add one since there is only one way to do the final denom */
}
