
#include "pushswap.h"

int	intrange(int* result, int a, int b, int sign)
{
	int	dix;
	int	tmp;

	dix = 10;
	tmp = *result * sign;
	if (tmp > 0 && (tmp * dix) < 0)
		return (-1);
	if (tmp < 0 && (tmp * dix) > 0)
		return (-2);
   	tmp = ((a * dix) + b) * (sign);
	if (sign < 0 && tmp < -2147483648)
		return (-3);
	else if (sign < 0 && tmp == -2147483648)
	{
		*result = (a * dix) + b;
		return 0;
	}
	*result = (a * dix) + b;
    if (a > 0 && b > 0 && *result < 0)
        return (-4);
    else if (a < 0 && b < 0 && *result > 0)
        return (-5);

    return (0);
}

int	ft_atoi(const char *str, int *error)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= 7 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		*error = intrange(&res, res, (*str - 48), sign);
		if (*error < 0)
			break ;
		str++;
	}
	return (res * sign);
}

// int main()
// {
// 	int h;
// 	h = 555;
// 	printf("hada result = %d\n", ft_atoi("-214", &h));
// 	printf("hada h = %d\n", h);
// }