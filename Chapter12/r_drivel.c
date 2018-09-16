#include <stdio.h>
#include <stdlib.h>

extern unsigned int srand1();
extern void srand2(unsigned int seed);

int main(void)
{
  unsigned int looptime, counter;
  printf("input a positive number which is means output how many random numbers and q means exit.\n");
  while(scanf("%u", &looptime))
  {
    srand2((unsigned int)time(0));
    for(counter = 0; counter < looptime; counter++)
    {
       printf("%u\n", srand1());
    }
    printf("input a positive number which is means output how many random numbers and q means exit.\n");
  }
  
}
