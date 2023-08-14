#include "so_long.h"

void	ft_print_error (int error)
{
	ft_putstr_fd("ERROR:", 2);
	if (error == 0)
		ft_putendl_fd("Incorrect number of arguments", 2);
	else if (error == 1)
		ft_putendl_fd("Incorrect argument", 2);
	else if (error == 2)
		ft_putendl_fd("Memory not allocated", 2);
	else if (error == 3)
		ft_putendl_fd("Invalid file descriptor", 2);
	else if (error == 4)
		ft_putendl_fd("Invalid map", 2);
	else if (error == 5)
		ft_putendl_fd("Wrong components", 2);
}

void	ft_free_error (t_data *data, int error)
{
	ft_print_error(error);
	free(data);
}

void	ft_free_map (t_data *data, int error)
{
	if (data->map_clone)
		free(data->map_clone);
	free(data->map);
	ft_print_error(error);
}

void	ft_free_all(t_data *data)
{
	ft_delete_sprites(data);
	mlx_terminate(data->mlx);
	free(data->map);
	free(data);
}