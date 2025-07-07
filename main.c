#include "cub3d.h"

static void	cub3d(char *argv)
{
	t_cub3d	cub3d;

	check_name(argv);
	init_cub3d(&cub3d);
	read_map(argv, &cub3d);
	validate_map(&cub3d);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		cub3d(argv[1]);
	else
		return (printf("Error\nIncorrect arguments\n"), 0);
	return (0);
}
