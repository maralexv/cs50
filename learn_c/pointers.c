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

To get the value of the thing pointed by the pointers, we use the * operator. 
For example (here, the address of c is assigned to the pc pointer; 
and to get the value stored in that address, we used *pc.):
int c;
c = 5;
int *pc;
pc = &c;
printf("%d", *pc);   // Output: 5

Note: In the above example, pc is a pointer, not *pc. 
You cannot and should not do something like *pc = &c;

Changing Value Pointed by Pointers:
int c;
c = 5;
int *pc;
pc = &c;
*pc = 1;
printf("%d", *pc);  // Ouptut: 1
printf("%d", c);    // Output: 1
We have assigned the address of c to the pc pointer.
Then, we changed *pc to 1 using *pc = 1;. 
Since pc and the address of c is the same, c will be equal to 1.

int *p = &c; 
_is equivalent to_ 
int *p:
p = &c;

Right and wrong:
int c, *pc;

Wrong: pc is address but c is not
pc = c; // Error

Wrong: &c is address but *pc is not
*pc = &c; // Error

Right: both &c and pc are addresses
pc = &c;

Right: both c and *pc values 
*pc = c;

*/

int main()
{
  int var = 15;
  printf("var: %d\n", var);

  // Notice the use of & before var
  printf("address of var: %p", &var);  
  return 0;
}