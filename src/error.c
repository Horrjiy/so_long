/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:29:39 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/18 11:45:50 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freem(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i] && map[i] != NULL)
			free(map[i++]);
		free(map);
	}
}

void	ft_error(char *message, char *s, char **map)
{
	ft_printf("Error\n%s\n", message);
	if (s)
		free(s);
	freem(map);
	exit(1 & 1);
}

// ft_putstr_fd(message, 1);
