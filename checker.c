#include "so_long.c"

static void	ft_map_copy(t_data *data)
{
	int	i;

	i = 0;
	data->map_clone = ft_strdup(data->map);
	while (data->map[i] && data->map[i] != 'P')
		i++;
	if (i == ft_strlen(data->map))
		ft_free_map(data, 5);
	data->player_pos = i;
}

static void	ft_check_components(t_data *data)
{
	int	i;

	i = -1;
	ft_map_copy(data);
	while (data->map[++i])
	{
		if (data->map[i] == 'C' || data->map[i] == 'E') 
		{
			data->nbr_collect += (data->map[i] == 'C');
			data->nbr_exits += (data->map[i] == 'E');
			ft_check_path(data, i, data->map[i]);
		}
		else if (data->map[i] == 'P')
			data->num_players++;
		else if (data->map[i] != '1' && data->map[i] != '0'
			&& data->map[i] != '\n')
			ft_free_map(data, 4);
	}
	if (data->num_collectables < 1 || data->num_exits != 1
		|| data->num_players != 1)
		ft_free_map(data, 5);
	free(map->map_clone);
}

static void	ft_vertical_wall(t_data *data, int len)
{
	int	i;

	i = 0;
	while(i < len)
	{
		if(data->map[i] == '1')
			i += data->map_width - 2;
		else
			ft_free_map(data, 3);
		if(data->map[i] == '1')
			i += 2;
		else
			ft_free_map(data, 4);
	}
}

static void	ft_horizontal_wall(t_data *data)
{
	int	i;
	int	len;
	int	j;

	i = -1;
	len = ft_strlen(data->map);
	j = len - data->map_width - 1; 
	while (++i != data->map_width)
	{
		if (data->map[i] != '1' && data->map[i] != '\n')
			ft_free_map(data, 3);
	}
	while(++j != len)
	{
		if (data->map[j] != '1' && data->map[j] != '\n')
			ft_free_map(data, 4);
	}
	ft_vertical_wall(data, len);
}

void ft_check_map(t_data *data, char *arg)
{
	int		fd;
	char	*aux;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		ft_free_map(data, 3);
	while(1)
	{
		data->map_height++;
		line = get_next_line(fd);
		if(!line)
			break;
		data->map_width = ft_strlen(line);
		aux = ft_strdup(data->map);
		free(data->map);
		data->map = ft_strjoin(aux, line);
		free(aux);
		free(line);
	}
	close(fd);
	ft_horizontal_wall(data);
	ft_check_components(data);
}