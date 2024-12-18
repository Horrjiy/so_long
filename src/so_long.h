/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:52:48 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/18 12:05:41 by mpoplow          ###   ########.fr       */
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
	char	**map;
	int		cake_x;
	int		cake_y;
	int		mapsizex;
	int		mapsizey;
	int		count0;
	int		count1;
	int		countc;
	int		counte;
	int		countp;
}			t_all;

void		freem(char **map);
void		ft_error(char *message, char *s, char **map);
void		ft_makewindow(t_all *all);
void		ft_hook(void *vptr);
int			ft_loadimg_0(t_all *all, int row, int column);
int			ft_loadimg_1(t_all *all, int row, int column);
int			ft_loadimg_c(t_all *all, int row, int column);
int			ft_loadimg_e(t_all *all, int row, int column);
int			ft_loadimg_p(t_all *all, int row, int column);
void		ft_mapanalyze(t_all *all, char *argv);
char		**ft_mapread(char *argv, t_all *all);
void		ft_wallcheck(t_all *all, char **map);
void		ft_wallsidecheck(t_all *all, char **map);
int			ft_waycheck(char **map, t_all *all);
bool		ft_path(char **tempmap, t_all *all);
bool		ft_walkcheck(char **tempmap, int row, int column, t_all *all);
void		ft_p_and_e(t_all *all, char *temp);
void		ft_buildmap(t_all *all);
void		ft_buildtile(t_all *all, int row, int column);

#endif
