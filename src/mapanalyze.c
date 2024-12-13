/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapanalyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:05:27 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/13 19:46:52 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapanalyze(t_all *all, char *argv)
{
	char	**map;

	all->mapsizex = 0;
	all->mapsizey = 0;
	map = ft_mapread(argv, all);
}

char	**ft_mapread(char *argv, t_all *all)
{
	int		fd;
	char	*temp;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_error(1, "open file failed"), NULL);
	temp = get_next_text(fd);
	if (!temp)
		return (ft_error(1, "malloc or reading failed"), NULL);
	close(fd);
	map = ft_split(temp, '\n');
	if (!map)
		return (free(temp), NULL);
	free(temp);
	while (map[all->mapsizey][0] != '\0')
		all->mapsizey++;
	while (map[all->mapsizex] != NULL)
	{
		if (ft_strlen(map[all->mapsizex]) != ft_strlen(map[0]))
			return (free(map), ft_error(1, "map line length wrong"), NULL);
		all->mapsizex++;
	}
	return (map);
}
