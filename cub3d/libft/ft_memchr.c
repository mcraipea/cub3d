/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:52:13 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/10 15:36:05 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	a;

	i = 0;
	str = (unsigned char*)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	return (0);
}
