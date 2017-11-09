#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copystr(char *to, char const *from, unsigned int n)
{
	unsigned int i;
	for(i = 1; i <= n; *to++ = *from++, i++)
		*to = '\0';
}

int main(int argc, char const *argv[])
{
	char const *str = NULL;
	char buf[100]={0};
	unsigned int len = 0, n = 0;
	int m = 0, i = 0;
	if(argc < 3 || argc > 4)
	{
		return -1;
	}
	str = argv[1];
	len = strlen(argv[1]);
	n = strlen(argv[2]);
	if(n > strlen(str))
	{
		return -1;
	}
	if(argc == 4)
	{
		m = atoi(argv[3]);
	}
	else 
	{
		m = 1;
	}
	while(strlen(str) >= strlen(str) - n)
	{
		copystr(buf, str, n);
		if (strcmp(buf, argv[2]) == 0)
		{
			if (++i == m)
			{
				printf("%u\n", len - strlen(++str));
				break;
			}
		}
		str++;
	}
	return 0;
}
