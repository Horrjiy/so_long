/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:03:50 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/18 11:30:02 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loadimg_0(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/0_ground.png");
	if (!tex_e)
		ft_error("", NULL, NULL);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		ft_error("", NULL, NULL);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	return (0);
}

int	ft_loadimg_1(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/1_wall.png");
	if (!tex_e)
		ft_error("", NULL, NULL);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		ft_error("", NULL, NULL);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	return (0);
}

int	ft_loadimg_c(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/c_greenc.png");
	if (!tex_e)
		ft_error("", NULL, NULL);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		ft_error("", NULL, NULL);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	return (0);
}

int	ft_loadimg_e(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/e_mouth.png");
	if (!tex_e)
		ft_error("", NULL, NULL);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		ft_error("", NULL, NULL);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	return (0);
}

int	ft_loadimg_p(t_all *all, int row, int column)
{
	mlx_texture_t *tex_e;
	mlx_image_t *img_e;

	tex_e = mlx_load_png("img/p_cake.png");
	if (!tex_e)
		ft_error("", NULL, NULL);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		ft_error("", NULL, NULL);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	return (0);
}
