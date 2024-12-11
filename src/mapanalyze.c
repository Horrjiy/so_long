/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapanalyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:05:27 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/11 22:39:44 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapanalyze(t_all *all, char *argv)
{
}

void	ft_mapread(t_all *all, char *argv)
{
	int fd;
	int readcheck;
	char temp[10];
	char *dest;

	fd = open(*argv, O_RDONLY);
	if ()
		while (1)
		{
			readcheck = read(fd, &temp, 10);
			temp[10] = '\0';
			if (readcheck == 0)
				break ;
			else if (readcheck == -1)
				return (ft_error(-1, "ERROR: map reading failed!"));
			dest = ft_strjoin();
		}

	return ;
}