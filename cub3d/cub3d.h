/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:32:48 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/02 16:13:01 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define K_ESC		53
# define K_W		13
# define K_S		1
# define K_A		0
# define K_D		2
# define K_LEFT		123
# define K_RIGHT	124

typedef struct		s_rgba
{
	uint8_t			b;
	uint8_t			g;
	uint8_t			r;
	uint8_t			a;
}					t_rgba;

typedef union		u_color
{
	int				value;
	t_rgba			rgba;
}					t_color;

typedef struct		s_vector
{
	float			x;
	float			y;
}					t_vector;

typedef struct		s_player
{
	float			x;
	float			y;
	t_vector		d;
	t_vector		p;
}					t_player;

typedef struct		s_map
{
	int				width;
	int				height;
	int				**values;
	int				size_line;
}					t_map;

typedef struct		s_pixel
{
	int				x;
	int				y;
}					t_pixel;

typedef struct		s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_texture;

typedef struct    	data_s
{
    void			*mlx_ptr;
    void			*mlx_win;
    void			*img_ptr;
    unsigned int	*param_img;
    int				bits;
    int				size_line;
    int				endian;
	t_texture		texture;
	t_pixel			pixel;
	t_player		player;
	t_map			map;
	t_color			color;
}                	data_t;

int			hook_keydown(int key, data_t data);
int			get_tile(t_map *map, int x, int y);
data_t		read_map(int fd, data_t data);
data_t		parse_texture(char *line, data_t data);
data_t		parse_couleur(char *line, data_t data);

#endif