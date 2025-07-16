/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:09 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:10 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_uc;
	unsigned char	*src_uc;
	size_t			i;

	if (!dest && !src && n > 0)
		return (NULL);
	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_uc[i] = src_uc[i];
		i ++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "ok";
	s2 = malloc ((strlen(s1) + 1) * (sizeof(char)));
	ft_memcpy(s2, s1, 3);
	printf("%s\n", s2);
	return (0);
}*/
