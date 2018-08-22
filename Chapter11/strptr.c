/*strptr.c --把字符串看成指针*/
#include <stdio.h>
int main(void)
{
  printf("%s %p %c\n","we", "are", *"champion");

  return 0;
}