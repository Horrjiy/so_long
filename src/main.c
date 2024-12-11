/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:40 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/11 22:18:30 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	mlx_t	*mlx;

	// t_all	*all;
	if (argc != 2)
		return (ft_error(1, "WRONG INPUT: 'argc != 2'!"));
	write(1, &argv[1][0], 1);
	mlx = mlx_init(1920, 1080, "so_long mpoplow42", true);
	if (!mlx)
		return (ft_error(1, "mlx failed"));
	// mapanalyze(all, argv[1])
	ft_makewindow(mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	loadimg_e(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

void	ft_hook(void *vptr)
{
	mlx_t	*mlx;

	mlx = vptr;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
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
