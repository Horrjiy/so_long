/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:52:48 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/13 19:45:41 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_all
{
	mlx_t	*mlx;
	int		cake_x;
	int		cake_y;
	int		mapsizex;
	int		mapsizey;
}			t_all;

void		ft_makewindow(mlx_t *mlx);
void		ft_error(int returnnb, char *message);
int32_t		ft_color_code(int r, int g, int b, int a);
void		ft_hook(void *vptr);
int			ft_loadimg_e(mlx_t *mlx);
void		ft_mapanalyze(t_all *all, char *argv);
char		**ft_mapread(char *argv, t_all *all);

#endif
