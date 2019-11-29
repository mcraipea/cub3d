/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:11:24 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/14 18:20:01 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*s11;
	const unsigned char		*s22;
	int						i;

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

char			*ft_strnstr(const char *src, const char *needle, size_t len)
{
	unsigned int		needle_len;
	char				*c;
	char				*cfin;

	if (*needle == '\0')
		return ((char *)(src));
	if (ft_strlen(needle) > ft_strlen(src))
		return (NULL);
	c = (char *)src;
	cfin = c + len;
	needle_len = ft_strlen(needle);
	if (0 == needle_len)
		return (c);
	cfin -= (needle_len - 1);
	while (c < cfin)
	{
		if (ft_strncmp(c, needle, needle_len) == 0)
			return (c);
		c++;
	}
	return (NULL);
}
