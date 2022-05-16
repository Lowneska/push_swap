#include "../includes/push_swap.h"

long	ft_atol(const char *str)
{
	int	signe;
	long	nbr;

	nbr = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (str[1] == '+' || str[1] == '-')
			return (0);
		if (*str++ == '-')
			signe = -1;
	}
	while (*str >= '0' && *str <= '9')
		nbr = (nbr * 10) + (*str++ - '0');
	return (nbr * signe);
}

int	ft_abs(int value)
{
	if (value >= 0)
		return (value);
	else
		return (value * (-1));
}