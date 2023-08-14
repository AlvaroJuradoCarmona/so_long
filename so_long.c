/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:55:40 by ajurado-          #+#    #+#             */
/*   Updated: 2023/08/02 19:10:30 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_check_args (t_data *data, char *arg)
{
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		ft_free_error(1);
	if (ft_strncmp(argv[1], "maps/", 5) != 0)
		ft_free_error(1);
}

static void ft_initialize(t_data *data, char *arg)
{
	ft_check_args(argv);
	data->moves = 0;
	data->map = ft_calloc(1, 1);
	if(!(data->map))
		ft_free_error(data, 2);
}

int main(int argc, char **argv)
{
	t_data	*data;
	
	if (argc != 2)
	{
		ft_print_error(0);
		exit(EXIT_FAILURE);
	}
	else
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
		{
			ft_free_error(data, 2);
			exit(EXIT_FAILURE);
		}
		ft_initialize(data, argv[1]);
		data->mlx = mlx_init(32 * (data->map_width - 1),
				32 * (data->map_height - 1), "so_long", true);
		if (!(data->mlx))
			ft_free_map_data(data, 0);
		ft_load_sprites(data);
		ft_window_map(data, 32);
		mlx_key_hook(data->mlx, &press_key, data);
		mlx_loop(data->mlx);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
}