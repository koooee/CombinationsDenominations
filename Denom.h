/*
Denom.h
Purpose:
  This file contains specifications for Denom.c
Programmer: Nick Kolegraff
Date: 6/19/2011
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>

#define MAX_DENOMINATIONS 10
#define TRUE 1
#define FALSE 0

double denoms[MAX_DENOMINATIONS] = {100.0, 50.0, 20.0, 10.0, 5.0, 1.0, .25, .1, .05, .01};

double input_ok(char *cinput); /* few checks to make sure input is ok for calculations */
double combinations(double input); /* Calculates the combinations of denominations */

