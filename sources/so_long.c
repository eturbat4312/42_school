/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:42:17 by eturbat           #+#    #+#             */
/*   Updated: 2022/03/31 12:45:07 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_show_image(t_vars *v)
{
	if (v->map[v->x][v->y] == '1')
		v->img = mlx_xpm_file_to_image(v->mlx, "includes1/sep.xpm", &v->s, \
				&v->s);
	if (v->map[v->x][v->y] == '0')
		v->img = mlx_xpm_file_to_image(v->mlx, "includes1/ground.xpm", &v->s, \
				&v->s);
	if (v->map[v->x][v->y] == 'C')
		v->img = mlx_xpm_file_to_image(v->mlx, "includes1/coin.xpm", &v->s, \
				&v->s);
	if (v->map[v->x][v->y] == 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "includes1/exit.xpm", \
				&v->s, &v->s);
		v->x_ext = v->x;
		v->y_ext = v->y;
	}
	if (v->map[v->x][v->y] == 'P')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "includes1/player.xpm", &v->s, \
				&v->s);
		v->x_pos = v->x;
		v->y_pos = v->y;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->y * v->s, v->x * v->s);
}

int	key_command(int keycode, t_vars *vars)
{
	int	a;

	a = 0;
	if (keycode == 53)
		ft_free_map(vars, "Esc");
	if (keycode == 13)
		a = move_up(vars, vars->x_pos - 1, vars->y_pos);
	if (keycode == 0)
		a = move_left(vars, vars->x_pos, vars->y_pos - 1);
	if (keycode == 1)
		a = move_down(vars, vars->x_pos + 1, vars->y_pos);
	if (keycode == 2)
		a = move_right(vars, vars->x_pos, vars->y_pos + 1);
	if (a == 2)
		ft_free_map(vars, "success!");
	return (0);
}

int	shutdown(int status, t_vars *var)
{
	(void)var;
	(void)status;
	printf("\nExit: [RED CROSS]\n");
	exit (0);
	return (0);
}

int	read_image(t_vars v)
{
	v.x = 0;
	v.y = 0;
	v.mlx = mlx_init();
	v.img = mlx_xpm_file_to_image(v.mlx, "includes1/ground.xpm", &v.s, &v.s);
	v.win = mlx_new_window(v.mlx, v.s * v.columns, v.s * v.lines, "Eturbat");
	mlx_hook(v.win, 17, 1L << 19, shutdown, &v);
	mlx_hook(v.win, 2, 1L << 0, key_command, &v);
	while (v.x < v.lines)
	{
		while (v.y < v.columns)
		{
			ft_show_image(&v);
			v.y++;
		}
		v.y = 0;
		v.x++;
	}
	mlx_loop(v.mlx);
	return (0);
}
