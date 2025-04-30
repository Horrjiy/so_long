/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:40 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/03 12:47:28 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_all	all;

	if (argc != 2)
		return (ft_error("WRONG INPUT: 'argc != 2'!", NULL, NULL), 1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	ft_bzero(&all, sizeof(t_all));
	ft_mapanalyze(&all, argv[1]);
	ft_introscreen();
	ft_makewindow(&all);
	ft_buildmap(&all);
	all.movescount = 0;
	ft_stepinit(&all);
	mlx_loop_hook(all.mlx, ft_playerhook, &all);
	mlx_loop_hook(all.mlx, ft_checkhook, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	freem(all.map);
	return (0);
}

void	ft_makewindow(t_all *all)
{
	mlx_image_t	*img;

	all->mlx = mlx_init((64 * all->mapsizex), (64 * all->mapsizey),
			"so_long mpoplow42", true);
	if (!all->mlx)
		ft_error("mlx failed", NULL, all->map);
	img = mlx_new_image(all->mlx, (64 * all->mapsizex), (64 * all->mapsizey));
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(all->mlx, img, 0, 0);
}

int	ft_introscreen(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tex;

	tex = mlx_load_png("img/bonusscreen/intro.png");
	if (!tex)
		return (ft_error("", NULL, NULL), 0);
	mlx = mlx_init(800, 600, "so_long_bonus by Mpoplow", false);
	img = mlx_texture_to_image(mlx, tex);
	if (!img)
		return (free(tex), ft_error("", NULL, NULL), 0);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, ft_esc_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_texture(tex);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}

void	ft_esc_hook(void *vptr)
{
	mlx_t	*mlx;

	mlx = vptr;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		mlx_close_window(mlx);
}
