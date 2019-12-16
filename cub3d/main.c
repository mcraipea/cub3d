/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:53:45 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/12 20:41:02 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int	hook_close(t_mlx *mlx)
{
	(void)mlx;
	exit(EXIT_SUCCESS);
	return (0);
}

int	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
	return (1);
}


int main(int argc, char **argv)
{
	t_mlx		data;

	if (argc != 2)
		return (error("error\nexample: ./cub3d [mapfile]"));
	read_map(argv[1], &data);
	init(&data);
	if (load_textures(&data) == 1)
		return (error("error: couldn't load textures"));
	init_position(&data.player);
	camera(&data);
	mlx_hook(data.window, 2, 1L << 0, hook_keydown, &data);
	mlx_hook(data.window, 17, 1L << 0, hook_close, &data);
	mlx_loop(&data.mlx);
	return (EXIT_SUCCESS);
}
