/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:32:12 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/14 16:49:03 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*s11;
	const unsigned char		*s22;
	int						i;

	if (!s1 && !s2)
		return (0);
	s11 = (const unsigned char*)s1;
	s22 = (const unsigned char*)s2;
	i = 0;
	while (n--)
	{
		if (s11[i] == '\0' || s11[i] != s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}
