/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapanalyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:05:27 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/25 21:37:41 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counts the number of characters in the map
void	ft_p_and_e(t_all *all, char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == 'C')
			all->countc++;
		if (temp[i] == 'E')
			all->counte++;
		if (temp[i] == 'P')
			all->countp++;
		if (temp[i] == '\n' && temp[i + 1] == '\n')
			ft_error("too many newlines in map!", temp, NULL);
			i++;
	}
	if (all->countp != 1 || all->counte != 1)
		ft_error("player or exit count is wrong!", temp, NULL);
}

//reads the map.ber and splits it into a 2D-array
char	**ft_mapread(char *argv, t_all *all)
{
	int		fd;
	char	*temp;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_error("open file failed", NULL, NULL), NULL);
	temp = get_next_text(fd);
	if (!temp)
		return (ft_error("malloc or reading failed", NULL, NULL), NULL);
	close(fd);
	ft_p_and_e(all, temp);
	map = ft_split(temp, '\n');
	free(temp);
	if (!map)
		return (ft_error("malloc failed", NULL, NULL), NULL);
	while (map[all->mapsizey] != NULL)
	{
		if (ft_strlen(map[all->mapsizey]) != ft_strlen(map[0]))
			return (ft_error("map line length wrong", NULL, map), NULL);
		all->mapsizey++;
	}
	all->mapsizex = ft_strlen(map[0]);
	return (map);
}

void	ft_mapanalyze(t_all *all, char *argv)
{
	all->mapsizex = 0;
	all->mapsizey = 0;
	all->map = ft_mapread(argv, all);
	ft_wallcheck(all, all->map);
	ft_wallsidecheck(all, all->map);
	ft_waycheck(all->map, all);
}
