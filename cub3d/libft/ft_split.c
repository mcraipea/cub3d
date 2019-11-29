/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:24:07 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/14 16:00:17 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char			*ft_sdup(char const *src, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char			**ft_tab_split(char **tab, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			if (!(tab[j++] = ft_sdup(&s[i], c)))
				return (NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

static char			**ft_free(char **tab)
{
	while (*tab)
	{
		free(*tab);
		(*tab)++;
	}
	free(tab);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	if (!(tab = ft_tab_split(tab, s, c)))
		ft_free(tab);
	return (tab);
}
