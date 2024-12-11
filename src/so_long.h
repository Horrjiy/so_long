/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:52:48 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/11 17:16:24 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_makewindow(mlx_t *mlx);
int		ft_error(int returnnb, char *message);
int32_t	color_code(int r, int g, int b, int a);
void	ft_hook(void *vptr);
int		loadimg_e(mlx_t *mlx);

typedef struct s_all
{
	int	cake_x;
	int	cake_y;
}		t_all;

#endif
