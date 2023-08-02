#include "so_long.h"

void ft_print_error (int error)
{
	ft_putstr_fd("ERROR:", 2);
	if (error == 0)
		ft_putendl_fd("Incorrect number of arguments", 2);
	else if (error == 1)
		ft_putendl_fd("Incorrect argument", 2);
}

void ft_free_error (t_data data, int error)
{
	ft_print_error(error);
	free(data);
}