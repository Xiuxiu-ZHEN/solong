/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:24 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:25 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		i ++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned char	*s;
	int	i;
	int	n;

	i = 0;
	n = 8;
	s = (unsigned char *) malloc (sizeof(char) * (strlen(s) + 1));
	ft_bzero(s, n);
	if (!s)
		return (1);
	while (i < n)
	{
		printf("%d", s[i]);
		i ++;
	}
	free(s);
	return (0);
}*/
