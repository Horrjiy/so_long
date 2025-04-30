/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapbuild.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:54:25 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/27 18:45:30 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_buildmap(t_all *all)
{
	int	row;
	int	column;

	row = 0;
	while (all->map[row] != NULL)
	{
		column = 0;
		while (all->map[row][column])
		{
			ft_buildtile(all, row, column);
			column++;
		}
		row++;
	}
	row = 0;
	while (all->map[row] != NULL)
	{
		column = 0;
		while (all->map[row][column])
		{
			ft_buildentities(all, row, column);
			column++;
		}
		row++;
	}
}

//loads the backround: Walls and ground tiles and the exit
void	ft_buildtile(t_all *all, int row, int column)
{
	if (all->map[row][column] == '0')
		ft_loadimg_0(all, row, column);
	if (all->map[row][column] == 'C')
		ft_loadimg_0(all, row, column);
	if (all->map[row][column] == 'P')
		ft_loadimg_0(all, row, column);
	if (all->map[row][column] == '1')
		ft_loadimg_1(all, row, column);
	if (all->map[row][column] == 'E')
		ft_loadimg_e(all, row, column);
}

//loads the entities: The player and collectibles
void	ft_buildentities(t_all *all, int row, int column)
{
	if (all->map[row][column] == 'C')
	{
		ft_loadimg_c(all, row, column);
	}
	if (all->map[row][column] == 'P')
	{
		ft_loadimg_p(all, row, column);
	}
}
