/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:49:38 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/10 14:41:51 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

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

static size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char			*ft_reverse(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = ft_strlen(s) - 1;
	j = 0;
	while (j < i)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i--;
		j++;
	}
	return (s);
}

static char			*ft_zero(void)
{
	char	*dest;

	if (!(dest = malloc(sizeof(char) * 2)))
		return (NULL);
	dest[0] = '0';
	dest[1] = '\0';
	return (dest);
}

char				*ft_itoa(int n)
{
	int					i;
	unsigned int		x;
	char				*dest;
	int					sign;

	i = 0;
	x = n < 0 ? -n : n;
	sign = n < 0 ? 1 : 0;
	if (n == 0)
		return (ft_zero());
	if (!(dest = malloc(sizeof(char) * (12))))
		return (NULL);
	ft_bzero(dest, 12);
	x = n < 0 ? -n : n;
	i = 0;
	while (x != 0)
	{
		dest[i++] = x % 10 + '0';
		x = x / 10;
	}
	if (n < 0)
		dest[i++] = '-';
	ft_reverse(dest);
	dest[i] = '\0';
	return (dest);
}
