/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:32:48 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/17 18:50:36 by mcraipea         ###   ########.fr       */
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
	int				draw_start;
	int				draw_end;
}					t_cast;

typedef struct		s_ray
{
	float			x;
	float			y;
	int				side;
	float			dist;
	int				height;
	t_image			*texture;
	float			dist_towall;
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
	int				angle_start;
}					t_player;

typedef struct		s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_texture;

typedef struct		s_sprite
{
	float			x;
	float			y;
	float			spriteX;
	float			spriteY;
	int				spriteScreenX;
	int				drawStartY;
	int				drawEndY;
	int				spriteWidth;
	int				drawStartX;
	int				drawEndX;
	float			dist;
	int				sizex;
	int				spriteHeight;
	float			angle;
	float			angle_f;
	float			angle_l;
	float			rotx;
	float			roty;
}					t_sprite;


typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	int				width_img;
	int				height_img;
	int				s_max;
	float			angle;
	t_texture		texture;
	t_image			*image;
	t_map			*map;
	t_player		player;
	t_image			*tex_no;
	t_image			*tex_so;
	t_image			*tex_we;
	t_image			*tex_ea;
	t_image			*tex_s;
	t_color			sol;
	t_color			plafond;
	t_sprite		*tsprite;
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
t_color		clerp(t_color c1, t_color c2);
void		draw_minimap(t_mlx *data);
int			error(char *str);
t_image		*xpm_image(char *xpm, t_mlx *mlx);
int			load_textures(t_mlx *mlx);
void		rotate_player(t_player *p, float angle);
void		move_player(t_player *p, t_map *m, float distance);
void		translate_player(t_player *p, t_map *m, float distance);
void		ft_do_dist_sprite(t_mlx *data);
void		ft_check_if_visible(t_mlx *data, float wall_dist);
void		ft_do_sort_sprite(t_mlx *data);
void		ft_draw_sprites(t_mlx *data, int pixel, t_sprite *sprite, float wall_dist);
int			ft_strchr_at_end(char *str, char *find);

#endif