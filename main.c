#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct	s_pixel
{
	int				x;
	int				y;
}				t_pixel;

typedef struct    data_s
{
    void			*mlx_ptr;
    void			*mlx_win;
    void			*img_ptr;
    unsigned int	*param_img;
    int				bits;
    int				size_line;
    int				endian;
	int				screen_width;
	int				screen_height;
	t_pixel			pixel;
}                 data_t;

int main(void)
{
	data_t		data;

	data.pixel.y = 0;
	data.pixel.x = 100;
	data.screen_height = 200;
	data.screen_width = 200;
	if ((data.mlx_ptr = mlx_init()) == NULL)
        	return (EXIT_FAILURE);
    	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.screen_width, data.screen_height, "mon Hello world")) == NULL)
        	return (EXIT_FAILURE);
    	if ((data.img_ptr = mlx_new_image(data.mlx_ptr, data.screen_width, data.screen_height)) == NULL)
		return(EXIT_FAILURE);
	data.param_img = (unsigned int *)mlx_get_data_addr(data.img_ptr, &data.bits, &data.size_line, &data.endian);
	while (data.pixel.x < 120)
	{
		data.pixel.y = 0;
		while (data.pixel.y < data.screen_height)
  		{
			data.param_img[(data.pixel.x) + (data.screen_height * data.pixel.y)] = 579200;
			data.pixel.y++;
		}
		data.pixel.x++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img_ptr, 0, 0);
	mlx_destroy_image(data.mlx_ptr, data.img_ptr);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
