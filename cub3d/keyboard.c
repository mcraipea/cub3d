/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:51:28 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/11 15:40:41 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		rotate_player(&mlx->player, -4.0f / 180.0f * M_PI);
	if (key == K_RIGHT)
		rotate_player(&mlx->player, 4.0f / 180.0f * M_PI);
	if (key == K_W)
		move_player(&mlx->player, mlx->map, 0.3f);
	if (key == K_S)
		move_player(&mlx->player, mlx->map, -0.3f);
	if (key == K_A)
		translate_player(&mlx->player, mlx->map, -0.1f);
	if (key == K_D)
		translate_player(&mlx->player, mlx->map, 0.1f);
	camera(mlx);
	return (0);
}
