#include <stdio.h>
#include <stdlib.h>

int main()
{
  float test1 = 16777215;
  float test2 = 16777216;

  float test3 = 16777216;
  float test4 = 16777217;

  if(test1 == test2)
  {
    printf("%f == %f\n", test1, test2);
  }
  else
  {
    printf("%f != %f\n", test1, test2);
  }

  if(test3 == test4)
  {
    printf("%f == %f\n", test3, test4);
  }
  else
  {
    printf("%f != %f\n", test3, test4);
  }
  return 0;
}