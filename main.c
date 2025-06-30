#include "cub3d.h"

static void	cub3d(void)
{
	t_cub3d	cub3d;

	init_cub3d(&cub3d);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		(void)argv;
		cub3d();
	}
	return (0);
}
