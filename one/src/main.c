#include "one.h"


int		main(int ac, char *av[])
{
	t_setting	*setting;

	if (ac != 5 && ac != 6)
		return (error_arg_count(ac));
	setting = parse_argv(ac, av);
	print_setting(setting);
	if (setting == NULL)
		return (error_arg_value());
	if (start_experiment(setting) == -1)
		return (error_unexpected());
	return (0);
}
