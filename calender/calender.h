#ifndef __CALENDER_H__

#define __CALENDER_H__

#include <stdio.h>

#define LEAP_YEAR 1

#define ILLEGAL_DATE 1

extern int months_and_days[13];

extern int is_illegal_date(int, int, int); 

extern int total_days(int, int);

extern int is_leap_year(int);

extern int week_day(int, int, int);

extern void display_week(int, int, int);

extern void display_month(int, int, int);
#endif // !__CALENDER_H__
