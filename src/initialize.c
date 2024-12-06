/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:50:57 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/06 20:06:28 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_makewindow()
{
	mlx_t *bollwerk;

	mlx_image_t *sprudel;
	bollwerk = mlx_init(69, 69, "ruppert", true);
	sprudel = mlx_new_image(bollwerk, 1080, 69);
	mlx_image_to_window(bollwerk, sprudel, 0, 0);
	mlx_loop(bollwerk);
	mlx_terminate(bollwerk);
}