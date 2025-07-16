/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:57 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:58 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*clear(t_list **result_lst, void *content, void (*del)(void *))
{
	if (content)
		del(content);
	ft_lstclear(result_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_lst;
	t_list	*in_result_lst;
	void	*content;

	result_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst -> content);
		if (!content)
			return (clear(&result_lst, NULL, del));
		in_result_lst = ft_lstnew(content);
		if (!in_result_lst)
			return (clear(&result_lst, content, del));
		ft_lstadd_back(&result_lst, in_result_lst);
		lst = lst -> next;
	}
	return (result_lst);
}
