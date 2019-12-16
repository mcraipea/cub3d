/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:25:26 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/16 19:25:39 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strchr_at_end(char *str, char *find)
{
	int		len_str;
	int		len_find;

	len_str = ft_strlen(str);
	len_find = ft_strlen(find);
	if ((len_str == 0 || len_find == 0) ||
			len_str <= len_find)
		return (-1);
	while (len_find > 0 && str[--len_str] == find[--len_find])
		;
	if (len_find == 0)
		return (0);
	return (-1);
}
