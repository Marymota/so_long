#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	res;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	if (res <= 2147483648)
		return (res * sign);
	if (res >= 2147483648 && sign > 0)
		return (-1);
	return (0);
}
