#include "calender.h"

int months_and_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 判断是否是闰年
int is_leap_year(int y){
  if((y % 4 == 0 && y % 100 != 0) || (y % 400 ==0)){
    return 1;
  }else{
    return 0;
  }
}

// 判断是否是合法日期
int is_illegal_date(int y, int m, int d){
  // 判断普通情况如2022 3 32是错误的
  if(m > 12 || m < 1 || d > 31 || d < 1){
    return 1;
  }

  if(m == 2 && is_leap_year(y)){
    months_and_days[2] = 29;
  }

  // 判断2.29 2.30 4.31这种日期
  if(d > months_and_days[m]){
    return 1;
  }
  return 0;
}

// 某月某日距多少天 如2022 7 8号距2022 1 1多少天
int total_days(int m, int d){
  int sum = 0;
  for (int i = 1; i < m; i++) {
    sum += months_and_days[i];
  }
  sum += d;
  return sum;
}

// 返回星期几
int week_day(int y, int m, int d){
  int count = 0;

	if(m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
	}

	count = (d + 2*m + 3*(m+1) / 5 + y + y / 4 - y / 100 + y / 400 + 1)%7;
	
	return count;
}

void display_week(y, m, d){
  int count = 0;

	//计算星期的函数	
	count = week_day(y, m, d);
  switch(count)
	{
		case 0:
			printf("%d-%d-%d is Sunday\n",y,m,d);
			break;
		case 1:
			printf("%d-%d-%d is Monday\n",y,m,d);
			break;
		case 2:
			printf("%d-%d-%d is Tuesday\n",y,m,d);
			break;
		case 3:
			printf("%d-%d-%d is Wednesday\n",y,m,d);
			break;
		case 4:
			printf("%d-%d-%d is Thursday\n",y,m,d);
			break;
		case 5:
			printf("%d-%d-%d is Friday\n",y,m,d);
			break;
		case 6:
			printf("%d-%d-%d is Saturday\n",y,m,d);
			break;
	}
}

void display_month(int y, int m, int d){
  int w = 0;
  printf("\n");
  printf("\n\t\t %d   year %d  month  \t\t\n", y, m);
  printf("\n SUN \t MON \t TUE \t WED \t THU \t FRI \t SAT \t\n");

  w = week_day(y,m,1);
  for (int i = 0; i < w; i++) {
    printf("\t");
  }

  for (int i = 1; i <= months_and_days[m]; i++) {
    printf(" %d \t", i);
    if((w + i) % 7 == 0){
      printf("\n\n");
    }
  }

  printf("\n");

}
