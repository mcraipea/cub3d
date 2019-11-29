/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:55:49 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/08 17:07:02 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		temp;

	i = 0;
	j = 0;
	temp = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (i < dstsize)
	{
		temp = i;
		while (src[j] && temp + j < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
		i = temp;
	}
	while (src[j])
		j++;
	return (i + j);
}
