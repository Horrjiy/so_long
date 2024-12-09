/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:40 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/09 17:33:58 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_error(1, "WRONG INPUT: 'argc != 2'!"));
	write(1, &argv[1][0], 1);
	ft_makewindow();
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
		mlx.
	}
	return ;
}

void	ft_makewindow(void)
{
	mlx_t			*mlxstruct;
	mlx_image_t		*img;
	mlx_texture_t	*pic_kek;

	mlxstruct = mlx_init(1920, 1080, "so_long mpoplow42", true);
	if (!mlxstruct)
		return ;
	img = mlx_new_image(mlxstruct, 1920, 1080);
	ft_memset(img->pixels, 9853, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlxstruct, img, 0, 0);
	pic_kek = mlx_load_png("img/kek.png");
	if (!pic_kek)
		ft_error(1, "");
	img = mlx_texture_to_image(mlxstruct, pic_kek);
	if (!img)
		ft_error(1, "");
	mlx_image_to_window(mlxstruct, img, 500, 500);
	mlx_loop_hook(mlxstruct, ft_hook, mlxstruct);
	mlx_loop(mlxstruct);
	mlx_terminate(mlxstruct);
}

int32_t	color_code(int r, int g, int b, int a)
{
	int32_t	rgba_value;

	rgba_value = (r << 24) | (g << 16) | (b << 8) | (a << 0);
	return (rgba_value);
}
