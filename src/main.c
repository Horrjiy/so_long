/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:40 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/13 19:47:25 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_all	all;

	if (argc != 2)
		return (ft_error(1, "WRONG INPUT: 'argc != 2'!"), 1);
	ft_bzero(&all, sizeof(t_all));
	all.mlx = mlx_init(1920, 1080, "so_long mpoplow42", true);
	if (!all.mlx)
		return (ft_error(1, "mlx failed"), 1);
	ft_mapanalyze(&all, argv[1]);
	ft_makewindow(all.mlx);
	mlx_loop_hook(all.mlx, ft_hook, &all);
	ft_loadimg_e(all.mlx);
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

void	ft_makewindow(mlx_t *mlx)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, 1920, 1080);
	ft_memset(img->pixels, 9853, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);
}

int32_t	ft_color_code(int r, int g, int b, int a)
{
	int32_t	rgba_value;

	rgba_value = (r << 24) | (g << 16) | (b << 8) | (a << 0);
	return (rgba_value);
}
