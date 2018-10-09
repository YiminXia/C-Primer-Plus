/*
*  使用sizeof查看系统中，各种类型的大小
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(void)
{
  printf("int          occupied %d bits in this centos.\n", sizeof(int) * CHAR_BIT);
  printf("unsigned int occupied %d bits in this centos.\n", sizeof(int) * CHAR_BIT);
  
  return 0;
}