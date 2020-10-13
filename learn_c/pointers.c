#include <stdio.h>

/*
Here is how we can declare pointers:
int* p;
int * p;
int *p;

To assign and addres pof a variable to a pointer we use &:
int *pc;
int c;
c = 5
pc = &c;
*/

int main()
{
  int var = 15;
  printf("var: %d\n", var);

  // Notice the use of & before var
  printf("address of var: %p", &var);  
  return 0;
}