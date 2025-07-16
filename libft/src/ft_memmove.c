/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:13 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:14 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (dest == src || n == 0)
		return (dest);
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			n --;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i ++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    void *dest = NULL;
    void *src = NULL;
    size_t n = 5;

    fflush(stdout); 
    ft_memmove(dest, src, n);
    printf("ft_memmove completed without crashing.\n");

    return 0;
}

int main(void)
{
    void *dest = NULL;
    void *src = NULL;
    size_t n = 5;

    fflush(stdout); 
    memmove(dest, src, n);
    printf("Standard memmove completed.\n");

    return 0;
}

*/
