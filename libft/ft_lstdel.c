/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:50:59 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/19 11:51:41 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	while ((*alst) != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = *alst;
		(*alst) = (*alst)->next;
		tmp->next = NULL;
		free(tmp);
	}
	alst = NULL;
}
