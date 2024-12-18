/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:40 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/18 12:06:01 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_all	all;

	if (argc != 2)
		return (ft_error("WRONG INPUT: 'argc != 2'!", NULL, NULL), 1);
	ft_bzero(&all, sizeof(t_all));
	ft_mapanalyze(&all, argv[1]);
	ft_makewindow(&all);
	ft_buildmap(&all);
	mlx_loop_hook(all.mlx, ft_hook, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}

void	ft_hook(void *vptr)
{
	t_all	*hookall;

	hookall = vptr;
	if (mlx_is_key_down(hookall->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(hookall->mlx);
	if (mlx_is_key_down(hookall->mlx, MLX_KEY_A))
	{
	}
}

void	ft_makewindow(t_all *all)
{
	mlx_image_t	*img;

	all->mlx = mlx_init((64 * all->mapsizex), (64 * all->mapsizey),
			"so_long mpoplow42", false);
	if (!all->mlx)
		ft_error("mlx failed", NULL, all->map);
	img = mlx_new_image(all->mlx, (64 * all->mapsizex), (64 * all->mapsizey));
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(all->mlx, img, 0, 0);
}
