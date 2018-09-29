#include <stdlib.h>
#include <stdio.h>

int main()
{
  int positiveInt;
  printf("please input a positive intiger.\n");
  scanf("%d", &positiveInt);
  int b = ~ positiveInt + 1;
  printf("%d\n", b);
  return 0;
}