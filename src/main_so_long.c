/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:40 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/08 20:36:12 by mpoplow          ###   ########.fr       */
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
	mlx_t* mlx = vptr;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	return ;
}

void	ft_makewindow(void)
{
	mlx_t		*bollwerk;
	mlx_image_t	*sprudel;

	bollwerk = mlx_init(1920, 1080, "so_long mpoplow42", true);
	if (!bollwerk)
		return;
	sprudel = mlx_new_image(bollwerk, 1920, 1080);
	ft_memset(sprudel->pixels, 9853, sprudel->width * sprudel->height
			* sizeof(int32_t));
	mlx_image_to_window(bollwerk, sprudel, 0, 0);
	mlx_loop_hook(bollwerk, ft_hook, bollwerk);
	mlx_loop(bollwerk);
	mlx_terminate(bollwerk);
}

int32_t	color_code(int r, int g, int b, int a)
{
	int32_t	rgba_value;

	rgba_value = (r << 24) | (g << 16) | (b << 8) | (a << 0);
	return (rgba_value);
}
