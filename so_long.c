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
			free(data);
			exit(EXIT_FAILURE);
		}
		ft_check_args(argv);
		exit(EXIT_SUCCESS);
	}
}