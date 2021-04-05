#include "one.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		num;
	int		digit_count;

	i = 0;
	sign = 1;
	num = 0;
	digit_count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '+' || str[i] == '-')
		sign *= str[i++] == '+' ? 1 : -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + str[i] - '0';
		++i;
		++digit_count;
		if (digit_count == 20)
			return (sign == -1) ? 0 : -1;
	}
	return (num * sign);
}

