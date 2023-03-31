/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:41:01 by mcloarec          #+#    #+#             */
/*   Updated: 2022/04/21 09:26:18 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_lst;

	if (*lst)
	{
		while (*lst)
		{
			new_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = new_lst;
		}
		*lst = NULL;
	}
}
