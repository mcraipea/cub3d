/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:11:29 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/17 14:21:53 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void		ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void			*ft_calloc(size_t count, size_t size)
{
	char	*dest;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(dest = malloc(sizeof(char) * size * count)))
		return (NULL);
	ft_bzero(dest, (count * size));
	return (dest);
}
