/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:48:32 by adoat             #+#    #+#             */
/*   Updated: 2018/08/27 15:48:33 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nv;
	t_list *prem;
	t_list *act;

	if (!lst || !f)
		return (NULL);
	prem = NULL;
	while (lst != NULL)
	{
		nv = (*f)(lst);
		if (prem != NULL)
		{
			act->next = nv;
			act = act->next;
		}
		else
		{
			prem = nv;
			act = prem;
		}
		lst = lst->next;
	}
	return (prem);
}
