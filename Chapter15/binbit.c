/*
* 不使用递归手段打印int类型的二进制
* step1：分一个字符数组，大小为sizeof(int) + 1
* step2: int类型的每一位都与一八进制数01做&运算，所得结果 + '0'写入字符数组中，最后一位置'\0'
* step3: 打印字符数组所组成的字符串，每隔四位空格一次
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define SIZE sizeof(int) * CHAR_BIT + 1


void int_bin(int n, char * strbin);
void printfbin(char * strbin);

int main(void)
{
  int input;
  char strbin[SIZE];
  printf("please input a int number(exit input q):\n");
  while(scanf("%d", &input) == 1)
  {
    int_bin(input, strbin);
    printfbin(strbin);
    printf("\nplease input a int number(exit input q):\n");
  }
  return 0;
}

void int_bin(int n, char * strbin)
{
  int i;
  for(i = SIZE - 2; i >= 0; i--, n >>= 1)
  {
    strbin[i] = (01 & n) + '0';
  }
  strbin[SIZE - 1] = '\0';
}
void printfbin(char * strbin)
{
  int i;
  for(i = 0; i < SIZE ; i++)
  {
    if(i % 4 == 0 && i != 0)
      putchar(' ');
    putchar(strbin[i]);
  }
}