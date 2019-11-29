/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:39:22 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/11 13:30:11 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*source;
	unsigned char	a;

	dst = (unsigned char*)dest;
	source = (unsigned char*)src;
	a = (unsigned char)c;
	while (n-- && *source != a)
		*dst++ = *source++;
	if (a && *source == a)
	{
		*dst = a;
		return (++dst);
	}
	else
		return (NULL);
}
