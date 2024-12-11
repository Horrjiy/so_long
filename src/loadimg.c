/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:03:50 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/11 22:18:20 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loadimg_e(mlx_t *mlx)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/P_cake.png");
	if (!tex_e)
		ft_error(1, "");
	img_e = mlx_texture_to_image(mlx, tex_e);
	if (!img_e)
		ft_error(1, "");
	mlx_image_to_window(mlx, img_e, 64, 64);
	return (0);
}
