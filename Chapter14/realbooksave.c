#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TITLELEN 40
#define AUTHORLEN 20
#define MAXBOOKS 5

struct book {
    char title[TITLELEN];
    char author[AUTHORLEN];
    float price;
};

char * s_gets(char *, int);

int main()
{ 
  int count = 0;
  int index, filecount;
  FILE * pbooks;
  int size = sizeof(struct book);
  struct book library[MAXBOOKS];
  struct book showlibrary[MAXBOOKS];
  
  if(NULL == (pbooks = fopen("books.dat", "a + b")))
  {
    printf("opened the file book.dat failed\n");
    exit(0);
  }
  
  rewind(pbooks);
  
  while(count < MAXBOOKS && 1 == fread(&library[count], size, 1, pbooks))
  {
    printf("the %d book :\n", count + 1);
    printf("name is %s, author is %s, the price is %f\n", library[count].title, library[count].author, library[count].price);
    count ++;
  }
  
  filecount = count;

  if(filecount == MAXBOOKS )
  {
      printf("the books.dat is full.\n ");
      exit(2);
  }
  
  printf("please input the title of book.\n");
  while(count < MAXBOOKS && s_gets(library[count].title, TITLELEN) && '\0' != library[count].title[0])
  {
    printf("please input the author of book.\n");
    s_gets(library[count].author, AUTHORLEN);
    printf("please input the price of book.\n");
    scanf("%f", &library[count].price);
    while ('\n' != getchar())
    {
      continue;
    }
    count++;
    if(count < MAXBOOKS)
    {
      printf("please input the title of book.\n");
    }

  }
  while(filecount < count && 1 == fwrite(&library[filecount], size, 1, pbooks))
  {
     filecount++;
  }
   
  rewind(pbooks);
  index = 0;
  while(index < MAXBOOKS && 1 == fread(&showlibrary[index], size, 1, pbooks))
  {
    printf("the %d book :\n", index + 1);
    printf("name is %s, author is %s, the price is %f\n", showlibrary[index].title, showlibrary[index].author, showlibrary[index].price);
    index ++;
  }
  fclose(pbooks);

  return 0;
}
char * s_gets(char * st, int n)
{
  char * val_ret;
  char * find;
  if(NULL != fgets(st, n, stdin))
  {
     find = strchr(st, '\n');
     if(NULL != find)
     {
       * find = '\0';
     }
     else
     {
       while('\n' != getchar())
       continue;
     }
  }
  val_ret = st;
  return val_ret;
}
