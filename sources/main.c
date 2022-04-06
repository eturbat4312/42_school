/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:22:29 by eturbat           #+#    #+#             */
/*   Updated: 2022/03/29 14:23:42 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (write(1, "Error\n", 6));
	if (argc == 2)
	{
		vars.lines = ft_lines(argv[1]);
		printf("lines : %d\n", vars.lines);
		vars.columns = ft_columns(argv[1]);
		printf("columns : %d\n", vars.columns);
		vars.map = map_storage(argv[1], vars);
		if (map_validity(&vars) == 1)
			ft_free_map(&vars, "Map Error");
		read_image(vars);
	}
	return (0);
}
