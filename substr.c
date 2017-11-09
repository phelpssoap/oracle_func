#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copystr(char *to, char const *from, unsigned int n)
{
	unsigned int i;
	for(i = 1; i <= n; i++)
	{
		*to++ = *from++;
		*to = '\0';
	}
}

int main(int argc, char const *argv[])
{
	char const *str1 = NULL;
	int m = 0, n = 0, len = 0;
	char buf[100]={0};
	if (argc == 4 && *argv[3] != '-')
	{
		str1 = argv[1];
		m = atoi(argv[3]);
		n = atoi(argv[2]);
		len = strlen(argv[1]);
		if(m < 0)
		{
			return -1;
		}
		if(n + len < 0)
		{
			return -1;
		}
		if(m > len)
		{
			goto jump;
		}
		if(n > 0 && n < len)
		{
			str1 = str1 + n - 1;
			copystr(buf, str1, m);
			printf("%s\n", buf);
			return 0;
		}
		if(n < 0)
		{
			str1 = str1 + len + n;
			copystr(buf, str1, m);
			printf("%s\n", buf);
			return 0;
		}
		return -1;
	}
	else if(argc == 3)
	{
		str1 = argv[1];
		n = atoi(argv[2]);
		len = strlen(argv[1]);
		if(n + len < 0)
		{
			return -1;
		}
		jump:
		if(n > 0 && n < len)
		{
			printf("%s\n", str1 + n - 1);
			return 0;
		}
		if(n < 0)
		{
			printf("%s\n", str1 + len + n);
			return 0;
		}
		return -1;
	}
	else
	{
		return -1;
	}
	return 0;
}
