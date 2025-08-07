#include "cub3d_bonus.h"

static void	debug_all_doors(t_cub3d *cub3d)
{
	int i;

	printf("=== Estado de todas las puertas ===\n");
	for (i = 0; i < cub3d->map.n_doors; i++)
	{
		t_door *d = &cub3d->map.door[i];
		printf("Puerta #%d en (%d, %d) - %s (anim: %.2f)\n",
			i, d->x, d->y, d->is_open ? "ABIERTA" : "CERRADA", d->animation);
	}
	printf("===================================\n");
}

static void	start_cub3d(t_cub3d *cub3d)
{
	starting_raycasting(cub3d, cub3d->player.direction);
	cub3d->mlx_ptr = mlx_init();
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d");
	cub3d->img_ptr = mlx_new_image(cub3d->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	init_image_buffer(cub3d);
	load_images(cub3d);
	raycast(cub3d);
	draw_minimap(cub3d);
	mlx_hook(cub3d->win_ptr, 6, 1L << 6, ft_mouse_hook, cub3d);
	mlx_hook(cub3d->win_ptr, 2, 1L << 0, key_press, cub3d);
	mlx_hook(cub3d->win_ptr, 3, 1L << 1, key_release, cub3d);
	mlx_hook(cub3d->win_ptr, 17, 0, close_window, cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, ft_key_hook, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}

static void	cub3d(char *argv)
{
	t_cub3d	cub3d;

	check_name(argv);
	init_cub3d(&cub3d);
	read_map(argv, &cub3d);
	validate_config(&cub3d);
	validate_textures(&cub3d);
	check_player(&cub3d);
	validate_map(&cub3d);
	color_floor_ceiling(&cub3d);
	find_doors(&cub3d);
	debug_all_doors(&cub3d);
	start_cub3d(&cub3d);
}


int	main(int argc, char **argv)
{
	if (argc == 2)
		cub3d(argv[1]);
	else
		return (printf("Error\nIncorrect arguments\n"), 0);
	return (0);
}
