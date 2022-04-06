/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:45:39 by eturbat           #+#    #+#             */
/*   Updated: 2022/03/31 12:45:56 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_vars *v)
{
	static int	moves;

	moves += 1;
	if (moves != 1)
		free(v->ptr);
	v->ptr = ft_itoa(moves);
	printf("moves : %d\n", moves);
	if (!v->ptr)
		return ;
	v->img = mlx_xpm_file_to_image(v->mlx, "includes1/sep.xpm", &v->s, &v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	v->str = mlx_string_put(v->mlx, v->win, 5, 15, 0x0000FF00, \
			v->ptr);
}

void	ft_free_map(t_vars *var, char *msg)
{
	int	x;

	x = 0;
	while (x < var->lines)
	{
		free(var->map[x]);
		x++;
	}
	free(var->map);
	if (!var->ptr)
		free(var->ptr);
	printf("\nExit: %s\n", msg);
	exit (0);
}

int	ft_lines(char *map)
{
	int		fd;
	int		nb;
	char	*line;

	nb = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit (0);
	line = get_next_line(fd);
	while (line)
	{
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (nb < 3)
		exit (0);
	return (nb);
}

int	ft_columns(char *map)
{
	int		fd;
	int		nb;
	int		ret;
	char	line[2];

	nb = -1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit (0);
	while (!ft_strchr(line, '\n'))
	{
		ret = read(fd, line, 1);
		if (ret < 0)
			return (0);
		line[ret] = '\0';
		nb++;
	}
	close(fd);
	if (nb < 3)
		exit (0);
	return (nb);
}
