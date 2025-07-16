/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:15 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:16 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i ++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	unsigned char	*s;
	int	i;

	i = 0;
	s = (unsigned char *) malloc (sizeof(char) * strlen(s));
	if (!s)
		return (1);
	ft_memset(s, 4,7);
	while (s[i] != '\0')
	{
		printf("%d ", s[i]);
		i ++;
	}
	free(s);
	return(0);
}*/
