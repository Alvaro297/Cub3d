#include "cub3d.h"

void	ft_print_cube(t_cub3d *cub3d)
{
	
}

static void	cub3d(char *argv)
{
	t_cub3d	cub3d;

	check_name(argv);
	init_cub3d(&cub3d);
	read_map(argv, &cub3d);
	ft_print_cube(&cub3d);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		cub3d(argv[1]);
	return (0);
}
