/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkhook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:20:15 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/25 19:00:50 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkhook(void *vptr)
{
	t_all	*hookall;

	hookall = vptr;
	if (hookall->c_collected == hookall->countc)
	{
		if (hookall->map[hookall->img_player->instances[0].y
				/ 64][hookall->img_player->instances[0].x / 64] == 'E')
			mlx_close_window(hookall->mlx);
	}
	if (hookall->map[hookall->img_player->instances[0].y
			/ 64][hookall->img_player->instances[0].x / 64] == 'C')
	{
		hookall->c_collected++;
		hookall->map[hookall->img_player->instances[0].y
			/ 64][hookall->img_player->instances[0].x / 64] = '0';
		ft_loadimg_0(hookall, (hookall->img_player->instances[0].y / 64),
			(hookall->img_player->instances[0].x / 64));
		ft_loadimg_p(hookall, (hookall->img_player->instances[0].y / 64),
			(hookall->img_player->instances[0].x / 64));
	}
}
