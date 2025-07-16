/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:28 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:29 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str ++;
	}
	return ((char *)str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*dest;

	str = "okcomputer";
	dest = malloc(1 * sizeof(char));
	dest = ft_strchr(str, 112);
	printf("%s\n", dest);
	return (0);
}*/
