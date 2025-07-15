#include "cub3d.h"

static void	start_cub3d(t_cub3d *cub3d)
{
	starting_raycasting(cub3d, cub3d->player.direction);
	cub3d->mlx_ptr = mlx_init();
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d");
	cub3d->img_ptr = mlx_new_image(cub3d->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	raycast(cub3d);
	mlx_key_hook(cub3d->win_ptr, ft_key_hook, cub3d);
	mlx_hook(cub3d->win_ptr, 6, 1L<<6, ft_mouse_hook, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}

static void	cub3d(char **argv)
{
	t_cub3d	cub3d;

	check_name(argv[1]);
	init_cub3d(&cub3d);
	read_map(argv[1], &cub3d);
	validate_config(&cub3d);
	validate_textures(&cub3d);
	validate_map(&cub3d);
	start_cub3d(&cub3d);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		cub3d(argv);
	else
		return (printf("Error\nIncorrect arguments\n"), 0);
	return (0);
}
