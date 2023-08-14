#include "so_long.h"

void	ft_load_sprites(t_data *data)
{
	mlx_texture_t	*aux;

	aux = mlx_load_png("./textures/background.png");
	data->wall_img = mlx_texture_to_image(data->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/collectable.png");
	data->bg_img = mlx_texture_to_image(data->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/exit.png");
	data->collect_img = mlx_texture_to_image(data->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/player.png");
	data->exit_img = mlx_texture_to_image(data->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("./textures/wall.png");
	data->player_img = mlx_texture_to_image(data->mlx, aux);
	mlx_delete_texture(aux);
}

void	ft_delete_sprites(t_data *data)
{
	mlx_delete_image(data->mlx, data->bg_img);
	mlx_delete_image(data->mlx, data->collectable_img);
	mlx_delete_image(data->mlx, data->exit_img);
	mlx_delete_image(data->mlx, data->player_img);
	mlx_delete_image(data->mlx, data->wall_img);
}

void	ft_window_map(t_data *data, int img_size)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (data->map[++i])
	{
		x = (i % data->map_width) * img_size;
		y = (i / data->map_width) * img_size;
		if (data->map[i] != '\n')
			mlx_image_to_window(data->mlx, data->bg_img, x, y);
		if (data->map[i] == '1')
			mlx_image_to_window(data->mlx, data->wall_img, x, y);
		else if (data->map[i] == 'C')
			mlx_image_to_window(data->mlx, data->collectable_img, x, y);
		else if (data->map[i] == 'E')
			mlx_image_to_window(data->mlx, data->exit_img, x, y);
		else if (data->map[i] == 'P')
			mlx_image_to_window(data->mlx, data->player_img, x, y);
	}
}