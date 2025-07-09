#include "cub3d.h"

static void	start_cub3d(t_cub3d *cub3d)
{
	while (1)
	{
		raycast(cub3d);
	}
}




static void	cub3d(char *argv)
{
	t_cub3d	cub3d;

	check_name(argv);
	init_cub3d(&cub3d);
	read_map(argv, &cub3d);
	validate_config(&cub3d);
	validate_textures(&cub3d);
	validate_map(&cub3d);
	start_cub3d(&cub3d);
	free_cub3d(&cub3d);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		cub3d(argv[1]);
	else
		return (printf("Error\nIncorrect arguments\n"), 0);
	return (0);
}
