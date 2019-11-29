/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:53:45 by mcraipea          #+#    #+#             */
/*   Updated: 2019/11/29 15:29:04 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	hook_close(data_t *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
	return (0);
}

int main(int argc, char **argv)
{
	data_t		data;
	int			fd;

	(void)argc;
	fd = open("map.txt", O_RDONLY);
	//read_map(fd);
	data.pixel.y = 0;
	data.pixel.x = 100;
	/*if ((data.mlx_ptr = mlx_init()) == NULL)
        	return (EXIT_FAILURE);
    	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.map.width, data.map.height, "mon Hello world")) == NULL)
        	return (EXIT_FAILURE);
    	if ((data.img_ptr = mlx_new_image(data.mlx_ptr, data.map.width, data.map.height)) == NULL)
		return(EXIT_FAILURE);
	data.param_img = (unsigned int *)mlx_get_data_addr(data.img_ptr, &data.bits, &data.size_line, &data.endian);
	while (data.pixel.x < 120)
	{
		data.pixel.y = 0;
		while (data.pixel.y < data.map.height)
  		{
			data.param_img[(data.pixel.x) + (data.map.height * data.pixel.y)] = 579200;
			data.pixel.y++;
		}
		data.pixel.x++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img_ptr, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L << 0, hook_keydown, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, hook_close, &data);
	mlx_destroy_image(data.mlx_ptr, data.img_ptr);
	mlx_loop(data.mlx_ptr);*/
	return (EXIT_SUCCESS);
}
