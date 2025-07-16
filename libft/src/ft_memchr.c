/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:04 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:05 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_uc;

	s_uc = (const unsigned char *) s;
	while (n --)
	{
		if (*s_uc == (unsigned char)c)
			return ((void *)(s_uc));
		s_uc ++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s;
	int	input;

	input = 112;
	s = "okcomputer";
	printf("%ld\n", (char *)ft_memchr(s, input, 10) - s);
	return (0);
}*/
