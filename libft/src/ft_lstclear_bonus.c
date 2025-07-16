/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:47 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:48 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_move;

	if (!(*lst))
		return ;
	while ((*lst) != NULL)
	{
		lst_move = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lst_move;
	}
}
