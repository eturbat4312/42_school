/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:45:13 by eturbat           #+#    #+#             */
/*   Updated: 2022/03/31 12:45:15 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	char	*ptr;
	int		str;
	int		x;
	int		y;
	int		lines;
	int		columns;
	int		x_pos;
	int		y_pos;
	int		x_ext;
	int		y_ext;
	int		s;
	int		player;
	int		collectible;
	int		ext;
}				t_vars;

char	**map_storage(char *path, t_vars var);
int		ft_lines(char *map);
int		ft_columns(char *map);
int		map_validity(t_vars *var);
int		read_image(t_vars v);
int		move_up(t_vars *v, int xx, int yy);
int		move_down(t_vars *v, int xx, int yy);
int		move_left(t_vars *v, int xx, int yy);
int		move_right(t_vars *v, int xx, int yy);
void	count_moves(t_vars *vars);
void	ft_free_map(t_vars *var, char *msg);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif
