/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:10:25 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/17 23:39:49 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//checks if top and bottom walls are all valid (character '1')
void	ft_wallcheck(t_all *all, char **map)
{
	int	i;

	i = 0;
	while (map[0] != NULL && map[0][i])
	{
		if (map[0][i] != '1')
			ft_error("Map: wall placement is invalid", NULL, map);
		i++;
	}
	i = 0;
	while (map[all->mapsizey - 1] != NULL && map[all->mapsizey - 1][i])
	{
		if (map[all->mapsizey - 1][i] != '1')
			ft_error("Map: wall placement is invalid", NULL, map);
		i++;
	}
}

//checks if left and right side walls are all valid (character '1')
void	ft_wallsidecheck(t_all *all, char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL && map[i][0])
	{
		if (map[i][0] != '1')
			ft_error("Map: side wall placement is invalid", NULL, map);
		i++;
	}
	i = 0;
	while (map[i] != NULL && map[i][all->mapsizex - 1])
	{
		if (map[i][all->mapsizex - 1] != '1')
			ft_error("Map: side wall placement is invalid", NULL, map);
		i++;
	}
}

bool	ft_walkcheck(char **tempmap, int row, int column, t_all *all)
{
	if (tempmap[row][column] == 'C' || tempmap[row][column] == 'E'
		|| tempmap[row][column] == '0')
	{
		if (row > 0 && tempmap[row - 1] != NULL)
			if (tempmap[row - 1][column] == 'P')
				return (true);
		if (row + 1 < all->mapsizey && tempmap[row + 1] != NULL)
			if (tempmap[row + 1][column] == 'P')
				return (true);
		if (column > 0 && tempmap[row][column - 1] == 'P')
			return (true);
		if (column + 1 < all->mapsizex && tempmap[row][column + 1] != '\0')
			if (tempmap[row][column + 1] == 'P')
				return (true);
	}
	return (false);
}

bool	ft_path(char **tempmap, t_all *all)
{
	int		row;
	int		column;
	bool	change;

	row = 0;
	change = false;
	while (tempmap[row] != NULL)
	{
		column = 0;
		while (tempmap[row][column])
		{
			if (ft_walkcheck(tempmap, row, column, all) == true)
			{
				tempmap[row][column] = 'P';
				change = true;
			}
			column++;
		}
		row++;
	}
	return (change);
}

int	ft_waycheck(char **map, t_all *all)
{
	char	**tempmap;
	bool	change;
	int		row;
	int		column;

	tempmap = ft_strstrdup((const char **)map);
	if (!tempmap)
		ft_error("malloc failed!", NULL, map);
	change = true;
	while (change == true)
		change = ft_path(tempmap, all);
	row = 0;
	while (tempmap[row] != NULL)
	{
		column = 0;
		while (tempmap[row][column] != '\0')
		{
			if (tempmap[row][column] == 'E' || tempmap[row][column] == 'C')
				return (freem(tempmap), ft_error("invalid path", NULL, map), 0);
			column++;
		}
		row++;
	}
	return (freem(tempmap), 0);
}
