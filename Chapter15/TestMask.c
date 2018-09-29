#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define LEN 10


void ShowTheBitsOfInteger();
char * s_gets(char * , int );



/**
1、输入一个int型
2、输出其二进制表示
*/

int main()
{

  char cmd[LEN];
  memset(cmd, 0, LEN);
  printf("==========================================================\n");
  printf("If you want to exit the process please press ENTER\n");
  s_gets(cmd,LEN);
  while(cmd[0]!='\0')
  {
    ShowTheBitsOfInteger(); 
    printf("If you want to exit the process please press ENTER\n");
    s_gets(cmd,LEN);
  }
 
  printf("==========================================================\n");
  return 0;
}

void ShowTheBitsOfInteger()
{
  int i, counter, bits;
  unsigned int mask = 0x80000000;
  int outbit;
  //printf("==========================================================\n");
  printf("please input an integer.\n");
  scanf("%d", &i);
  while(getchar()!='\n')
    continue;
  bits = sizeof(int) * CHAR_BIT;

  for(counter = 0; counter < bits; counter++)
  {
    outbit = i & mask; 

    if(counter != 0 && counter % 4 == 0)
    {
      printf(",");
    }
    mask = mask >> 1;
    printf("%d", outbit==0 ? 0 : 1);
  }
  printf("\n");
  //printf("==========================================================\n");
}


char * s_gets(char * cmd, int n)
{
  char * ret_val;
  int i = 0;

  ret_val = fgets(cmd, n, stdin);
  if(ret_val)
  {
    while(cmd[i] != '\n' && cmd[i] != '\0')
      i++;
    if(cmd[i] == '\n')
      cmd[i] = '\0';
    else
      while(getchar()!='\n')
         continue;
  }
  return ret_val;

}