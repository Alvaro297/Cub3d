# include "../cub3d.h"

void	print_cub3d(t_cub3d *cub3d)
{
	int	i;

	printf("=== TEXTURAS ===\n");
	printf("NO: %s\n", cub3d->map.tex_no);
	printf("SO: %s\n", cub3d->map.tex_so);
	printf("WE: %s\n", cub3d->map.tex_we);
	printf("EA: %s\n", cub3d->map.tex_ea);
	printf("\n=== COLORES ===\n");
	printf("Suelo: %d,%d,%d\n",
		cub3d->map.rgb_floor[0],
		cub3d->map.rgb_floor[1],
		cub3d->map.rgb_floor[2]);
	printf("Techo: %d,%d,%d\n",
		cub3d->map.rgb_ceiling[0],
		cub3d->map.rgb_ceiling[1],
		cub3d->map.rgb_ceiling[2]);
	printf("\n=== MAPA ===\n");
	i = 0;
	while (cub3d->map.matriz[i])
	{
		printf("%s", cub3d->map.matriz[i]);
		i++;
	}
	printf("\n=== JUGADOR ===\n");
	printf("Posición X: %.1f\n", cub3d->player.x_position);
	printf("Posición Y: %.1f\n", cub3d->player.y_position);
	printf("Dirección: %c\n", cub3d->player.direction);
	printf("Ángulo: %.1f\n", cub3d->player.angle);
	printf("================\n");
}
