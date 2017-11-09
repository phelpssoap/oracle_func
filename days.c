#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int error(int y, int m, int d, char c, int *array);
void leapyear(int y, int *feb, int *sumday);
int totalday(int m, int d, int *array);
void calcdate1(int *m, int *d, int days, int *array);
void calcdate2(int *m, int *d, int days, int *array);
void sub(int *y, int *m, int *d, int *sumday, int *array1, int *array2, int *feb, int *days, int operday);
void add(int *y, int *m, int *d, int *sumday, int *array1, int *array2, int *feb, int *days, int operday);

int main(int argc, char *argv[]) 
{
	int y=0, m=0, d=0, days=0, operday=0, sumday=0, len1, len2, len3;
	char c=48;
	int date[8] = {0};
	int operdays[4] = {0};
	int array[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
	int i;

	if(argc < 4)
	{
		printf("[ERROR] not enough arguments usage: yyyymmdd +/- day \n");
		return 0;
	}

	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	len3 = strlen(argv[3]);

	if (len3 > 4)
	{
		printf("[ERROR] too large %s between 0 and 9999 \n", argv[3]);
	}

	for(i = 0; i < len3; i++)
	{
		if(*(argv[3]) < 48 || *(argv[3]) > 57)
		{
			printf("a [ERRPR] invalid number \n");
			return 0;
		}
		operdays[i] = *argv[3] - '0';
		argv[3]++;
	}

	switch(len3)
	{
		case 1:
			operday = operdays[0];
			break;
		case 2:
			operday = operdays[0]*10 + operdays[1];
			break;
		case 3:
			operday = operdays[0]*100 + operdays[1]*10 + operdays[2];
			break;
		case 4:
			operday = operdays[0]*1000 + operdays[1]*100 + operdays[2]*10 + operdays[3];
			break;
		default:
			return 0;
	}

	if((*argv[2] != 43 && *argv[2] != 45) || len2 > 1)
	{
		printf("b [ERROR] invalid operation \n");
		return 0;
	}

	c = *argv[2];

	if(len1 != 8)
	{
		printf("c [ERROR] invalid date \n");
		return 0;
	}

	for(i = 0; i < 8; i++)
	{
		if(*argv[1] < 48 || *argv[1] > 57)
		{
			printf("d [ERRPR] invalid number \n");
			return 0;
		}
		date[i] = *argv[1] - '0';
		argv[1]++;
	}

	y = date[0]*1000+date[1]*100+date[2]*10+date[3];
	m = date[4]*10+date[5];
	d = date[6]*10+date[7];

	leapyear(y, &array[2], &sumday);

	if (error(y, m, d, c, &array[0]) == 0)
	{
		return 0;
	}
	if (c == '-')
	{
		days = totalday(m, d, &array[1]);
		sub(&y, &m, &d, &sumday, &array[1], &array[12], &array[2], &days, operday);
	}
	else if (c == '+')
	{
		days = sumday - totalday(m, d, &array[1]);
		add(&y, &m, &d, &sumday, &array[1], &array[12], &array[2], &days, operday);
	}
	else
	{
		return 0;
	}

	if (d < 10 && m < 10)
	{
		printf("%d0%d0%d \n", y, m, d);
	}
	else if (d < 10 && m >= 10)
	{
		printf("%d%d0%d \n", y, m, d);
	}
	else if (d >= 10 && m < 10)
	{
		printf("%d0%d%d \n", y, m, d);
	}
	else
	{
		printf("%d%d%d \n", y, m, d);
	}
	return 0;
}

int error(int y, int m, int d, char c, int *array)
{
	if (d < 1 || d > *(array + m))
	{
		printf("[ERROR] invalid day %d: between 1 and %d \n", d, *(array + m));
		return 0;
	}
	if (m < 1 || m > 12)
	{
		printf("[ERROR] invalid month %d: between 1 and 12 \n", m);
		return 0;
	}
	if (y < 1900 || y > 2100)
	{
		printf("[ERROR] invalid year %d: between 1990 and 2100 \n", y);
		return 0;
	}
	if (c != '+' && c != '-')
	{
		printf("[ERROR] invalid operation %c: + or - \n", c);
		return 0;
	}
	return 1;
}

void leapyear(int y, int *feb, int *sumday)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		*feb = 29;
		*sumday = 366;
	}
	else
	{
		*feb = 28;
		*sumday = 365;
	}
}

int totalday(int m, int d, int *array)
{
	int i;
	int total = 0;
	for (i = 1; i < m; i++)
	{
		total += *array;
		array++;
	}
	total += d;
	return total;
}

void calcdate1(int *m, int *d, int days, int *array)
{
	int i;
	*m = 1;
	for (i = 0; i < 12; i++)
	{
		if (days <= *array)
		{
			*d = days;
			break;
		}
		else
		{
			days = days - *array;
			(*m)++;
		}
		array++;
	}
}

void calcdate2(int *m, int *d, int days, int *array)
{
	int i;
	*m = 12;
	for (i = 0; i < 12; i++)
	{
		if (days > *array)
		{
			days = days - *array;
			(*m)--;
		}
		else if (days == *array)
		{
			array--;
			*d = *array;
			(*m)--;
			break;
		}
		else
		{
			*d = *array - days;
			break;
		}
		array--;
	}
}

void sub(int *y, int *m, int *d, int *sumday, int *array1, int *array2, int *feb, int *days, int operday)
{
	if (*days > operday)
	{
		*days = *days - operday;
		calcdate1(m, d, *days, array1);
	}
	else if (*days == operday)
	{
		(*y)--;
		*m = 12;
		*d = 31;
	}
	else
	{
		*days = operday - *days;
		while(1)
		{
			(*y)--;
			leapyear(*y, feb, sumday);
			if (*days < *sumday)
			{
				calcdate2(m, d, *days, array2);
				break;
			}
			else if (*days == *sumday)
			{
				(*y)--;
				*m = 12;
				*d = 31;
				break;
			}
			else
			{
				*days = *days - *sumday;
			}
		}
	}
}

void add(int *y, int *m, int *d, int *sumday, int *array1, int *array2, int *feb, int *days, int operday)
{
	if (operday < *days)
	{
		*days = *days - operday;
		calcdate2(m, d, *days, array2);
	}
	else if (operday == *days)
	{
		*m = 12;
		*d = 31;
	}
	else
	{
		*days = operday - *days;
		while(1)
		{
			(*y)++;
			leapyear(*y, feb, sumday);
			if (*days < *sumday)
			{
				calcdate1(m, d, *days, array1);
				break;
			}
			else if (*days == *sumday)
			{
				*m = 12;
				*d = 31;
				break;
			}
			else
			{
				*days = *days - *sumday;
			}
		}
	}
}
