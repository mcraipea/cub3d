/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:58:06 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/14 18:44:56 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned int		i;
	int					n;
	unsigned int		result;
	int					x;

	i = 0;
	n = 0;
	x = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		result = result * 10 + str[i++] - '0';
	if (n == 1)
		return (int)(-result);
	return (int)(result);
}
