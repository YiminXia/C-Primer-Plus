#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLELEN 40
#define AUTHORLEN 20
#define MAXBOOKS 10

struct book {
       char title[TITLELEN];
       char author[AUTHORLEN];
       float price  ;    
};

char * s_gets(char *, int );

int main()
{
   char * st = (char *) malloc(AUTHORLEN);
   printf("input a name use Enter to exit\n");
   s_gets(st,AUTHORLEN);
   printf("name is %s\n",st);
   return 0;
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
    
  ret_val = fgets(st, n, stdin);//只录入n-1个字符，最后自动加\0
  if(NULL != ret_val)
  {
     find = strchr(st, '\n');
     if(NULL != find)
     {
         *find = '\0';
     }
     else
     {
        while(getchar() != '\n')
        {
          continue;
        }
     }
  }
  return ret_val;
}