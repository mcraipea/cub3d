/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:22:34 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/12 16:39:17 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*dst;
	const char		*source;

	if (n == 0 || (!dest && !src))
		return (dest);
	dst = (char*)dest;
	source = (const char*)src;
	while (n--)
		*dst++ = *source++;
	return (dest);
}
