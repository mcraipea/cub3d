/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:32:48 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/06 16:18:12 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
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

# define VIEW_DIST 	10
# define TEX_MAP_SIZE 20

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

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct		s_map
{
	int				width;
	int				height;
	int				**values;
}					t_map;

typedef struct		s_vector
{
	float			x;
	float			y;
}					t_vector;

typedef struct		s_cast
{
	int				mapX;
	int				mapY;
	float			sideDistX;
	float			sideDistY;
	float			deltaDistX;
	float			deltaDistY;
	int				stepX;
	int				stepY;
	float			wallDist;
}					t_cast;

typedef struct		s_ray
{
	float			x;
	float			y;
	int				side;
	float			dist;
	float			light;
	int				height;
	t_image			*texture;
	int				tex_x;
	float			fx;
	float			fy;
}					t_ray;

typedef struct		s_player
{
	float			x;
	float			y;
	t_vector		d;
	t_vector		p;
}					t_player;

typedef struct		s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_texture;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	int				width_img;
	int				height_img;
	t_texture		texture;
	t_image			*image;
	t_map			*map;
	t_player		player;
	t_image			*tex[TEX_MAP_SIZE];
	int				max_tex;
	t_color			sol;
	t_color			plafond;
	t_image			*floor;
	t_image			*ceiling;
}					t_mlx;

int			hook_keydown(int key, t_mlx *data);
void		read_map(char *argv, t_mlx *data);
t_mlx		*parse_texture(char *line, t_mlx *data);
t_mlx		*parse_couleur(char *line, t_mlx *data);
void		init_position(t_player *player);
int			get_position(t_map *map, int x, int y);
void		screen(t_mlx *data);
void		camera(t_mlx *data);
void		init(t_mlx *data);
t_image		*new_image(t_mlx *mlx, int w, int h);
t_image		*del_image(t_mlx *mlx, t_image *img);
t_color		get_pixel(t_image *image, int x, int y);
void		clear_image(t_image *image);
void		image_set_pixel(t_image *image, int x, int y, int color);
t_color		clerp(t_color c1, t_color c2, double p);
void		draw_minimap(t_mlx *data);
int			error(char *str);
t_image		*xpm_image(char *xpm, t_mlx *mlx);
int			load_textures(t_mlx *mlx);
void		rotate_player(t_player *p, float angle);
void		move_player(t_player *p, t_map *m, float distance);

#endif