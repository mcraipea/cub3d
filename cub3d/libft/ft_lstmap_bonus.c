/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:19:06 by mcraipea          #+#    #+#             */
/*   Updated: 2019/10/14 16:12:55 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list		*lst_cpy;
	t_list		*lst_start;

	if (!lst || !f)
		return (NULL);
	lst_start = NULL;
	while (lst)
	{
		if (!lst_start)
		{
			if (!(lst_cpy = ft_lstnew((*f)(lst->content))))
				return (NULL);
			lst_start = lst_cpy;
		}
		else
			lst_cpy->next = ft_lstnew((*f)(lst->content));
		lst = lst->next;
	}
	return (lst_start);
}
