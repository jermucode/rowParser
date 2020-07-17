//#include <stdio.h>
//#include <stdlib.h>

int tabcount(char *str)
{
	char *ptr = str;
	int tabcount = 0;
	while(*ptr)
	{
		if(*ptr == '\t')
		{
			tabcount+=1;
		}
		ptr++;
	}
	return tabcount;
}

