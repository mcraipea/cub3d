/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:28:05 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/11 13:16:40 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int			ft_charisset(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t		ft_strlen(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void			ft_bzero(void *s, size_t n)
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

char				*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_bzero(dest, (ft_strlen(s1) + 1));
	while (ft_charisset(s1[i], set) == 1 && s1[i])
		i++;
	while (s1[i])
		dest[j++] = s1[i++];
	if (j == 0)
	{
		dest[0] = '\0';
		return (dest);
	}
	j--;
	while (ft_charisset(dest[j], set) == 1 && j >= 1)
		dest[j--] = '\0';
	return (dest);
}
