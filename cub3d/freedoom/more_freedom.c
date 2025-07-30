#include "../cub3d.h"

void	free_matriz(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map.matriz[i])
	{
		free(cub3d->map.matriz[i]);
		i++;
	}
	free(cub3d->map.matriz);
}

void	free_norm_matriz(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map.matriz_norm[i])
	{
		free(cub3d->map.matriz_norm[i]);
		i++;
	}
	free(cub3d->map.matriz_norm);
}
