/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:40 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/06 14:26:57 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		x;
	mlx_t	*bollwerk;

	//	mlx_image_t	*sprudel;
	bollwerk = mlx_init(69, 69, "ruppert", true);
	// sprudel = mlx_new_image(bollwerk, 69, 69);
	// mlx_image_to_window(bollwerk, sprudel, 0, 0);
	mlx_loop(bollwerk);
	mlx_terminate(bollwerk);
	x = 69;
	return (69);
}
