#include <stdio.h>
#include <stdlib.h>

#define WEEK 7
void showArray(const int [], int);
void showArray1(const int * , int);

int main()
{
   int week[WEEK] = {1,2,3,4,5,6,7};
   showArray(week,WEEK);
   showArray1(week,WEEK);
   return 0;

}
void showArray(const int week[], int n)
{
  int index;
  for(index = 0; index < n; index++)
  {
    printf("week[%d] = %d", index, week[index]);
  }
  week[2] = 25;
}

void showArray1(const  int * week, int n)
{
  int index;
  for(index = 0; index < n; index++)
  {
    printf("week[%d] = %d", index, week[index]);
  }
 *(week + 2) = 25;
}