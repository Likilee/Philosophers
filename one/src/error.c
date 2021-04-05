#include "one.h"

int		error_arg_count(int	ac)
{
	printf("Error: Wrong argument amount\n : %d", ac - 1);
	return (0);
}

int		error_arg_value(void)
{
	printf("Error: Wrong argument value\n");
	return (0);
}

int		error_unexpected(void)
{
	printf("Error: Unexpectected\n");
	return (0);
}

void	*free_setting_and_return_null(t_setting	*setting)
{
	free(setting);
	return (NULL);
}
