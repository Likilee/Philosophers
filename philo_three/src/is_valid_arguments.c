#include "three.h"

t_bool	is_valid_arguments(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (FALSE);
	if (ft_atoi(av[1]) <= 0 ||
		ft_atoi(av[2]) <= 0 ||
		ft_atoi(av[3]) <= 0 ||
		ft_atoi(av[4]) <= 0)
		return (FALSE);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (FALSE);
	return (TRUE);
}
