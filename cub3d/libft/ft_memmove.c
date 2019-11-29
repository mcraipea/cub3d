/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:48:07 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/12 16:44:39 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;

	dst = (char*)dest;
	source = (const char*)src;
	while (n--)
	{
		*dst++ = *source++;
	}
	return (dest);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (len == 0 || (!dst && !src))
		return (dst);
	dest = (char*)dst;
	source = (const char*)src;
	if (source <= dest)
	{
		dest += len - 1;
		source += len - 1;
		while (len--)
			*dest-- = *source--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
