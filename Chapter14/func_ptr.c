#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 20

void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void ToDoNothing(char *);
void eatline();

char * s_gets(char *, int);

char showMenu(char *);
void (*pfun) (char *);
void show(void (*pfun)(char *), char *);

int main()
{
  char line[LEN];
  char copyline[LEN];
  char choice = 0;

  printf("test main.please input a string:\n");

  while(NULL != s_gets(line, LEN) && '\0' != line[0])
  {
    while(showMenu(&choice))
    {
      switch(choice)
      {
        case 'u': 
            pfun = ToUpper; 
            break;
        case 'l': 
            pfun = ToLower; 
            break;
        case 't': 
            pfun = Transpose; 
            break;
        case 'd': 
            pfun = ToDoNothing;
            break;
      }
      strcpy(copyline,line);
      //pfun(copyline);
      //printf("%s\n",copyline);
      show(pfun,copyline);
    }
    printf("input another string or press Enter to quit.\n");
  }
  return 0;
}

char  showMenu(char * choice)
{
  //char userinput;
  
  printf("show the choices.\n");
  printf("u:uppercase. l:lowercase.\n");
  printf("t:transpose. d;todonothing.\n");
  printf("e:if you want exit please input e.\n");
  printf("please input your choice (end with Enter):");
  *choice = getchar();
  //printf("show your choice :%c",choice);
  if('e' != *choice)
  {
    eatline();
    return *choice;
  }
  eatline();
  return 0;
}

void show(void (* pfun)(char *), char * st)
{
  (*pfun)(st);
  printf("%s\n",st);
}



void ToUpper(char * st)
{
  while(* st)
  {
    *st = toupper(* st);
    st++;
  }
  return;
}

void ToLower(char * st)
{
  while(* st)
  {
    *st = tolower(*st);
    st++;
  }
  return;
}

void Transpose(char * st)
{
  while(* st)
  {
    if(*st == toupper(*st))
    {
      *st = tolower(*st);
    }
    else
    {
      *st = toupper(*st);
    }
    st++;
  }
  return;
}
void ToDoNothing(char * st)
{
  return;
}
void eatline()
{
  while(getchar() != '\n')
  {
    continue;
  }
}



char * s_gets(char * st, int n)
{
  char * find;
  char * val_ret;
  
  val_ret = fgets(st, n, stdin);
  if(val_ret)
  {
    find = strchr(st, '\n');
    if(find)
    {
      * find = '\0';
    }
    while(getchar() != '\n')
    {
      continue;
    }
    return val_ret;
  }
}




















