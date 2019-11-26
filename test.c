#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

int main(void)
{
    data_t        data;
    char	*str;

	str = "Bonjour";
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 200, 200, "mon Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_string_put(data.mlx_ptr, data.mlx_win, 100, 100, 6579200, str);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
