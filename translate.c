#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char const *str1 = NULL;
	char const *str2 = NULL;
	char const *str3 = NULL;
	unsigned int n = 0, m = 0, i = 0, j = 0;
	char buf[100]={0};
	char *c = buf;
	if(argc == 3)
	{
		return 0;
	}
	else if(argc == 4)
	{
		str1 = argv[1];
		str2 = argv[2];
		str3 = argv[3];
		n = strlen(argv[2]);
		m = strlen(argv[3]);
		if(n > m)
		{
			while(*str1 != '\0')
			{
				i = 0;
				j = 0;
				while(strlen(str2) > 0)
				{
					j++;
					if(*str1 == *str2)
					{
						if(j > m)
						{
							i = 1;
							break;
						}
						*c++ = *str3;
						i = 1;
						break;
					}
					str2++;
					str3++;
				}
				if(i == 0)
				{
					*c++ = *str1;
				}
				str2 = argv[2];
				str3 = argv[3];
				str1++;
			}
			*c = '\0';
			printf("%s\n", buf);
			return 0;
		}
		else
		{
			while(*str1 != '\0')
			{
				i = 0;
				while(strlen(str2) > 0)
				{
					if(*str1 == *str2)
					{
						*c++ = *str3;
						i = 1;
						break;
					}
					str2++;
					str3++;
				}
				if(i == 0)
				{
					*c++ = *str1;
				}
				str2 = argv[2];
				str3 = argv[3];
				str1++;
			}
			*c = '\0';
			printf("%s\n", buf);
			return 0;
		}
	}
	else
	{
		return -1;
	}
	return 0;
}
