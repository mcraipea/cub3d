/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:53:45 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 14:01:15 by mcraipea         ###   ########.fr       */
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

int			error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
	return (1);
}

static int	verif_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
			return (error("error\nexample: ./cub3d [mapfile]"));
		if (argc > 3 && (ft_strncmp(argv[2], "--save", 7)) != 0)
			return (error("error\nexample: ./cub3d [mapfile]"));
	}
	if (ft_strchr_at_end(argv[1], ".cub") == -1)
		return (error("error\nexample of mapfile : map.cub"));
	return (1);
}

int			main(int argc, char **argv)
{
	t_mlx		data;
	int			fd;

	verif_arg(argc, argv);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (error("error\nyour mapfile doesn't exist"));
	read_map(argv[1], &data);
	init(&data);
	if (load_textures(&data) == 1)
		return (error("error: couldn't load textures"));
	init_position(&data.player);
	camera(&data);
	if (argc == 3 && (!ft_strncmp(argv[2], "--save", 7)))
	{
		export_as_bmp("./screens/screenshot.bmp", data.image->ptr,
			data.width_img, data.height_img);
		return (EXIT_SUCCESS);
	}
	mlx_hook(data.window, 2, 1L << 0, hook_keydown, &data);
	mlx_hook(data.window, 17, 1L << 0, hook_close, &data);
	mlx_loop(&data.mlx);
	return (EXIT_SUCCESS);
}
