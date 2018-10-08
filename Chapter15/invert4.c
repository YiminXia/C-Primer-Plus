/*
* int类型，显示其二进制
* 1：分一块33字节大小的内存区域，用于存放‘0’‘1’字节，这次试用malloc，跟free
* 2：用一个8进制数01来跟int类型的数，每一bit位做&运算，然后+‘0’，存放于malloc所分配的内存中
* 3：打印数字，每隔4位空一格。
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define SIZE sizeof(int) * CHAR_BIT + 1

char * inttobits(int, char *);
void show_bstr(char *);
int invert_end(int, int);

int main(void)
{
  int input;
  char * outputStr = (char *)malloc(SIZE);
  printf("input an int which you want to invert to binary(q to exit):\n");
  while(scanf("%d", &input) == 1)
  {
    outputStr = inttobits(input, outputStr);
    show_bstr(outputStr);
    printf("\nthe last 4 bit invert is:\n"); 
    input = invert_end(4, input);
    outputStr = inttobits(input, outputStr);
    show_bstr(outputStr);
    printf("\ninput an int which you want to invert to binary(q to exit):\n"); 
  }
  free(outputStr);
  return 0;
}

char * inttobits(int input, char * outputStr)
{
  int i;
  int mask;
  for(i = SIZE - 1; i > 0; i--, input >>= 1)
  {
    outputStr[i - 1] = (input & 01) + '0';
  }
  outputStr[SIZE - 1] = '\0';
  return outputStr;
}

void show_bstr(char * outputStr)
{
  int i;
  for(i = 0; i < SIZE; i++)
  {
    if(i % 4 == 0 && i != 0)
      putchar(' ');
    putchar(outputStr[i]);
  }
}

int invert_end(int num, int input)
{
  int mask = 1;
  int i;
  for(i = 1; i < num; i++)
  {
    mask <<= 1;
    mask ++; 
  }
  return mask ^ input;
}