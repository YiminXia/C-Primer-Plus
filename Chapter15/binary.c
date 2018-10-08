/*
*使用递归方法计算出一个unsigned long 正整数的二进制表达式
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void to_binary(unsigned long );


int main(void)
{
  unsigned long input;
  printf("please input an unsigned long positive number (exit press q):\n");
  while(scanf("%lu", &input) == 1)
  {
    to_binary(input);
    printf("\nplease input an unsigned long positive number (exit press q):\n");
  }
  return 0;
}

void to_binary(unsigned long n)
{
  int r;
  r = n % 2;
  if(n >= 2)
    to_binary(n / 2);
  putchar(r != 0 ? '1' : '0');
}