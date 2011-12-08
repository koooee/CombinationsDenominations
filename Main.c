/*

Main.c
Purpose: 
  Serves as the main entry file for the denominations problem.
Programmer: Nick Kolegraff
Date: 6/19/2011

*/

#include "Denom.c"

int main(int argc, char* argv[])
{

  double input;
  char *p = malloc(sizeof(char));
  double combin;
  /* quick parameter check */
  if(argc > 2 || argc <= 1)
    {
      printf("Program takes one argument, a decimal number\n");
      exit(EXIT_FAILURE);
    }

  input = input_ok(argv[1]);
  combin = combinations(input);
  printf("Total Combinations: %.309g\n", combin);
 
}
