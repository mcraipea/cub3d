/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_gnl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:05:56 by mcraipea          #+#    #+#             */
/*   Updated: 2019/11/29 12:50:57 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnjoin_gnl(char const *s1, char const *s2, unsigned int n)
{
	int				i;
	int				j;
	int				size;
	char			*dest;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		size = 0;
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i] && n > 0)
	{
		dest[j++] = s2[i++];
		n--;
	}
	dest[j] = '\0';
	free((void*)s1);
	return (dest);
}
