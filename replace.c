#include <stdio.h>
#include <string.h>

void copystr(char *to, char const *from, unsigned int n)
{
	unsigned int i;
	for(i=1; i<=n; i++)
	{
		*to++ = *from++;
		//*to = '\0';
	}
}

int main(int argc, char const *argv[])
{
	char const *str1 = NULL;
	char const *str2 = NULL;
	char const *str3 = NULL;
	unsigned int len = 0, n = 0, m = 0;
	char buf1[100]={0};
	char buf2[1024]={0};
	char *c = buf2;
	if(argc == 3)
	{
		str1 = argv[1];
		str2 = argv[2];
		len = strlen(argv[1]);
		n = strlen(argv[2]);
		if(n > len)
		{
			return -1;
		}
		while(strlen(str1) >= n)
		{
			copystr(buf1, str1, n);
			if(strcmp(buf1, str2) == 0)
			{
				str1+=n;
			}
			else
			{
				*c++ = *str1;
				str1++;
			}
		}
		copystr(c, str1, n-1);
		printf("%s\n", buf2);
		return 0;
	}
	else if(argc == 4)
	{
		str1 = argv[1];
		str2 = argv[2];
		str3 = argv[3];
		len = strlen(argv[1]);
		n = strlen(argv[2]);
		m = strlen(argv[3]);
		if(n > len)
		{
			return -1;
		}
		while(strlen(str1) >= n)
		{
			copystr(buf1, str1, n);
			if(strncmp(buf1, str2, n) == 0)
			{
				copystr(c, str3, m);
				str1+=n;
				c+=m;
			}
			else
			{
				*c++ = *str1;
				str1++;
			}
		}
		copystr(c, str1, n-1);
		printf("%s\n", buf2);
		return 0;
	}
	else
	{
		return -1;
	}
	return 0;
}
