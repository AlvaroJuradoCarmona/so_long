/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:44:11 by ajurado-          #+#    #+#             */
/*   Updated: 2023/08/17 12:44:11 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*ft_moves(t_data *data, int player_pos)
{
	int	*moves;

	moves = (int *) malloc(4 * sizeof(int));
	moves[0] = player_pos - data->map_width - 1;
	moves[1] = player_pos + 1;
	moves[2] = player_pos + data->map_width + 1;
	moves[3] = player_pos - 1;
	return (moves);
}

static int	ft_path_exist(t_data *data, int player_pos, int comp_pos, char comp)
{
	int	i;
	int	*moves;

	i = -1;
	moves = ft_moves(data, player_pos);
	if (player_pos == comp_pos)
		return (free(moves), 1);
	while (++i < 4)
	{
		if (data->map_clone[moves[i]] != '1' && (comp == 'E'
				|| (comp == 'C' && data->map_clone[moves[i]] != 'E')))
		{
			data->map_clone[player_pos] = '1';
			if (ft_path_exist(data, moves[i], comp_pos, comp))
				return (free(moves), 1);
		}
	}
	return (free(moves), 0);
}

void	ft_check_path(t_data *data, int comp_pos, char component)
{
	if (!ft_path_exist(data, data->player_pos, comp_pos, component))
		ft_free_map(data, 4);
	free(data->map_clone);
	data->map_clone = ft_strdup(data->map);
}

int	ft_check_exit(t_data *data, char pos)
{
	if (pos == 'E' && data->num_collectables != 0)
	{
		ft_putendl_fd("A few collectibles are still available!", 1);
		return (1);
	}
	else if (pos == 'E' && data->num_collectables == 0)
	{
		ft_putendl_fd("You won the match!", 1);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
