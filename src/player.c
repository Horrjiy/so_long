/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:17:07 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/29 21:45:08 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_playerleft(t_all *hookall)
{
	if (hookall->map[hookall->img_player->instances[0].y
			/ 64][(hookall->img_player->instances[0].x - 64) / 64] != '1')
	{
		hookall->img_player->instances[0].x -= 64;
		++hookall->movescount;
		ft_stepcount_bonus(hookall);
	}
	usleep(150000);
}

static void	ft_playerright(t_all *hookall)
{
	if (hookall->map[hookall->img_player->instances[0].y
			/ 64][(hookall->img_player->instances[0].x + 64) / 64] != '1')
	{
		hookall->img_player->instances[0].x += 64;
		++hookall->movescount;
		ft_stepcount_bonus(hookall);
	}
	usleep(150000);
}

static void	ft_playerup(t_all *hookall)
{
	if (hookall->map[(hookall->img_player->instances[0].y - 64)
			/ 64][hookall->img_player->instances[0].x / 64] != '1')
	{
		hookall->img_player->instances[0].y -= 64;
		++hookall->movescount;
		ft_stepcount_bonus(hookall);
	}
	usleep(150000);
}

static void	ft_playerdown(t_all *hookall)
{
	if (hookall->map[(hookall->img_player->instances[0].y + 64)
			/ 64][hookall->img_player->instances[0].x / 64] != '1')
	{
		hookall->img_player->instances[0].y += 64;
		++hookall->movescount;
		ft_stepcount_bonus(hookall);
	}
	usleep(150000);
}

void	ft_playerhook(void *vptr)
{
	t_all	*hookall;

	hookall = vptr;
	if (mlx_is_key_down(hookall->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(hookall->mlx);
	if (mlx_is_key_down(hookall->mlx, MLX_KEY_A))
		ft_playerleft(hookall);
	if (mlx_is_key_down(hookall->mlx, MLX_KEY_D))
		ft_playerright(hookall);
	if (mlx_is_key_down(hookall->mlx, MLX_KEY_W))
		ft_playerup(hookall);
	if (mlx_is_key_down(hookall->mlx, MLX_KEY_S))
		ft_playerdown(hookall);
}
