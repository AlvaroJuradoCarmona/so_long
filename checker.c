#include "so_long.c"

void ft_check_args (char **argv)
{
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		ft_print_error(1);
}