/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:51:28 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/10 19:36:03 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		rotate_player(&mlx->player, -2.0f / 180.0f * M_PI);
	if (key == K_RIGHT)
		rotate_player(&mlx->player, 2.0f / 180.0f * M_PI);
	if (key == K_W)
		move_player(&mlx->player, mlx->map, 0.2f);
	if (key == K_S)
		move_player(&mlx->player, mlx->map, -0.2f);
	if (key == K_A)
		translate_player(&mlx->player, mlx->map, -0.05f);
	if (key == K_D)
		translate_player(&mlx->player, mlx->map, 0.05f);
	camera(mlx);
	return (0);
}
