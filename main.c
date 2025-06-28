#include "cub3d.h"

static void	cub3d(char **argv)
{
	t_cub3d	cub3d;

	init_cub3d(&cub3d);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		*argv++;
		cub3d(argv);
	}
	return (0);
}
