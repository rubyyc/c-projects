#include "calender.h"
#include <stdio.h>

int main (int argc, char *argv[])
{
  int year = 0, month = 0, day = 0;
  int res = 0;
  printf("please input year month day:\n");
  scanf("%d%d%d", &year, &month, &day);
  res = is_illegal_date(year, month, day);
  // 如果是非法日期,如2020 2 30 2020 4 31这种
  if(res == ILLEGAL_DATE){
    printf("Your input is error!\n");
    return -1;
  }

  res = is_leap_year(year);
  if(res){
    printf("%d %d %d is leap year!\n", year, month, day);
  }else{
    printf("%d %d %d is not leap year!\n", year, month, day);
  }

  res = total_days(month, day);
  printf("%d %d %d is %d day of the year!\n", year, month, day, res);

  display_week(year, month, day);
  display_month(year, month, day);
  return 0;
}
