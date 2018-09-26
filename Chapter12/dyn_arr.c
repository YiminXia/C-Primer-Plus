#include <stdio.h>
#include <stdlib.h>

int main()
{
  
  int max;
  int i = 0;
  double * ptd;

  printf("input max length of array.\n");
  if(1 != scanf("%d", &max))
  {
    printf("Number is not correctly entered.\n");
    exit(EXIT_FAILURE);
  }
  ptd = (double *)malloc(sizeof(double) * max);
  if(NULL == ptd)
  {
    printf("memery can not alloc.\n");
    exit(EXIT_FAILURE);
  }

  printf("input the numbers.\n");
  while(i < max && scanf("%lf", &ptd[i]) == 1)
      i++;
  
  for(i = 0; i < max; i++)
  {
    printf("%7.2lf ", ptd[i]);
    if(i % 7 == 6)
    {
      puts("");
    }
  }
  puts("");
  puts("done.");
  
  free(ptd);
  return 0;

}