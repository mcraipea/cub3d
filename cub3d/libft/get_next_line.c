/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:51:01 by mcraipea          #+#    #+#             */
/*   Updated: 2019/11/27 17:08:35 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char		buffer[4097];
	char			buffer_temp[1];
	int				ret;
	int				ret2;

	ret = 1;
	if (fd <= -1 || line == NULL || (read(fd, buffer_temp, 0) < 0))
		return (-1);
	*line = ft_strdup("");
	while (ret && (ret2 = ft_strchr_gnl(buffer, '\n')) == -1)
	{
		if (!(*line = ft_strnjoin_gnl(*line, buffer, 4096)))
			return (-1);
		if ((ret = read(fd, buffer, 4096)) == 0)
		{
			return (0);
		}
		buffer[ret] = 0;
	}
	if (!(*line = ft_strnjoin_gnl(*line, buffer, ret2)))
		return (-1);
	if (ret)
		ft_strcpy(buffer, &buffer[ret2 + 1]);
	return (1);
}
