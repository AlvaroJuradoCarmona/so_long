/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:55:59 by ajurado-          #+#    #+#             */
/*   Updated: 2023/08/21 17:30:52 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*bg_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
	mlx_image_t		*collectable_img;
	mlx_image_t		*exit_img;
	char			*map;
	char			*map_clone;
	int				map_width;
	int				map_height;
	int				player_pos;
	int				num_collectables;
	int				num_exits;
	int				num_players;
	int				game_moves;
}	t_data;

void	ft_check_map(t_data *data, char *arg);
void	ft_check_path(t_data *data, int comp_pos, char component);
int		ft_check_exit(t_data *data, char pos);
void	ft_load_sprites(t_data *data);
void	ft_delete_sprites(t_data *data);
void	ft_window_map(t_data *data, int img_size);
void	ft_print_error(int error);
void	ft_free_error(t_data *data, int error);
void	ft_free_map(t_data *data, int error);
void	ft_free_all(t_data *data);
void	ft_controller_key(mlx_key_data_t keydata, void *game_data);

#endif