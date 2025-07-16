/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:27 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:28 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num > 0 && size > 0 && num > (size_t)(-1) / size)
		return (NULL);
	ptr = malloc (num * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, num * size);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
