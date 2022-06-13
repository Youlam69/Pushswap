#include <stdio.h>
#include <unistd.h>

int chackalpha(char **str)
{
	int i = 1;
	int j = 0;
	
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			printf("%c\n", str[i][j]);
			if( str[i][j] < '0' || str[i][j] > '9')
				return -1;
			j++;
		}
		i++;
	}
	return 0;
}