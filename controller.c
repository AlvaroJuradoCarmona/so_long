/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:44:39 by ajurado-          #+#    #+#             */
/*   Updated: 2023/08/17 12:44:39 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_controller_up(t_data *data)
{
	int		i;
	int		up;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	up = i - data->map_width - 1;
	if (data->map[up] != '1'
		&& !ft_check_exit(data, data->map[up]))
	{
		data->game_moves++;
		if (data->map[up] == 'C')
			data->num_collectables--;
		data->map[i] = '0';
		data->map[up] = 'P';
		moves = ft_itoa(data->game_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_window_map(data, 32);
}

static void	ft_controller_right(t_data *data)
{
	int		i;
	int		right;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	right = i + 1;
	if (data->map[right] != '1'
		&& !ft_check_exit(data, data->map[right]))
	{
		data->game_moves++;
		if (data->map[right] == 'C')
			data->num_collectables--;
		data->map[i] = '0';
		data->map[right] = 'P';
		moves = ft_itoa(data->game_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_window_map(data, 32);
}

static void	ft_controller_down(t_data *data)
{
	int		i;
	int		down;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	down = i + data->map_width + 1;
	if (data->map[down] != '1'
		&& !ft_check_exit(data, data->map[down]))
	{
		data->game_moves++;
		if (data->map[down] == 'C')
			data->num_collectables--;
		data->map[i] = '0';
		data->map[down] = 'P';
		moves = ft_itoa(data->game_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_window_map(data, 32);
}

static void	ft_controller_left(t_data *data)
{
	int		i;
	int		left;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	left = i - 1;
	if (data->map[left] != '1'
		&& !ft_check_exit(data, data->map[left]))
	{
		data->game_moves++;
		if (data->map[left] == 'C')
			data->num_collectables--;
		data->map[i] = '0';
		data->map[left] = 'P';
		moves = ft_itoa(data->game_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_window_map(data, 32);
}

void	ft_controller_key(mlx_key_data_t keydata, void *game_data)
{
	t_data	*data;

	(void) keydata;
	data = game_data;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_controller_up(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_controller_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_controller_down(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_controller_right(data);
}
