/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepcount_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:55:53 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/02 16:04:15 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_stepinit(t_all *all)
{
	ft_loadimg_boot(all);
	ft_loadimg_num(all, 1, "img/stepbonus/num0.png");
	ft_loadimg_num(all, 2, "img/stepbonus/num0.png");
	all->countermax = 99;
	if (all->mapsizex >= 4)
	{
		ft_loadimg_num(all, 3, "img/stepbonus/num0.png");
		all->countermax = 999;
	}
	if (all->mapsizex >= 5)
	{
		ft_loadimg_num(all, 4, "img/stepbonus/num0.png");
		all->countermax = 9999;
	}
	if (all->mapsizex >= 6)
	{
		ft_loadimg_num(all, 5, "img/stepbonus/num0.png");
		all->countermax = 99999;
	}
}

void	ft_stepcount_bonus(t_all *all)
{
	char	imgpath[23];
	char	*stepstr;
	int		digit;
	int		numlength;
	int		position;

	if (all->mapsizex >= 6)
		position = 6;
	else
		position = all->mapsizex;
	ft_loadimg_boot(all);
	if (all->movescount <= all->countermax)
	{
		stepstr = ft_itoa(all->movescount);
		ft_strlcpy(imgpath, "img/stepbonus/numx.png", 23);
		digit = 0;
		numlength = ft_strlen(stepstr);
		while (digit < numlength)
		{
			imgpath[17] = stepstr[digit];
			ft_loadimg_num(all, ((position - numlength) + digit), imgpath);
			digit++;
		}
		free(stepstr);
	}
}

void	ft_loadimg_num(t_all *all, int column, char *imgpath)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	ft_loadimg_1(all, 0, column);
	tex = mlx_load_png(imgpath);
	if (!tex)
		ft_error("", NULL, all->map);
	img = mlx_texture_to_image(all->mlx, tex);
	if (!img)
	{
		free(tex);
		ft_error("", NULL, NULL);
	}
	mlx_image_to_window(all->mlx, img, (64 * column), (64 * 0));
	mlx_delete_texture(tex);
}

int	ft_loadimg_boot(t_all *all)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png("img/stepbonus/boot.png");
	if (!tex)
		ft_error("", NULL, all->map);
	img = mlx_texture_to_image(all->mlx, tex);
	if (!img)
		return (free(tex), ft_error("", NULL, all->map), 1);
	mlx_image_to_window(all->mlx, img, (64 * 0), (64 * 0));
	mlx_delete_texture(tex);
	return (0);
}
