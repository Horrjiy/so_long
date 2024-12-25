/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:03:50 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/25 19:18:22 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loadimg_0(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/0_ground.png");
	if (!tex_e)
		ft_error("", NULL, all->map);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		return (free(tex_e), ft_error("", NULL, NULL), 1);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	mlx_delete_texture(tex_e);
	return (0);
}

int	ft_loadimg_1(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/1_wall.png");
	if (!tex_e)
		ft_error("", NULL, all->map);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		return (free(tex_e), ft_error("", NULL, all->map), 1);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	mlx_delete_texture(tex_e);
	return (0);
}

int	ft_loadimg_c(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/c_greenc.png");
	if (!tex_e)
		ft_error("", NULL, all->map);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		return (free(tex_e), ft_error("", NULL, all->map), 1);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	mlx_delete_texture(tex_e);
	return (0);
}

int	ft_loadimg_e(t_all *all, int row, int column)
{
	mlx_texture_t	*tex_e;
	mlx_image_t		*img_e;

	tex_e = mlx_load_png("img/e_mouth.png");
	if (!tex_e)
		ft_error("", NULL, all->map);
	img_e = mlx_texture_to_image(all->mlx, tex_e);
	if (!img_e)
		return (free(tex_e), ft_error("", NULL, all->map), 1);
	mlx_image_to_window(all->mlx, img_e, (64 * column), (64 * row));
	mlx_delete_texture(tex_e);
	return (0);
}

int	ft_loadimg_p(t_all *all, int row, int column)
{
	all->tex_player = mlx_load_png("img/p_cake.png");
	if (!all->tex_player)
		ft_error("", NULL, all->map);
	all->img_player = mlx_texture_to_image(all->mlx, all->tex_player);
	if (!all->img_player)
		return (free(all->tex_player), ft_error("", NULL, all->map), 1);
	mlx_image_to_window(all->mlx, all->img_player, (64 * column), (64 * row));
	mlx_delete_texture(all->tex_player);
	return (0);
}
