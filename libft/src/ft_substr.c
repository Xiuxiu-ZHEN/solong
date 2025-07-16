/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:57 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:58 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;
	size_t	actual_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len - start < len)
		actual_len = s_len - start;
	else
		actual_len = len;
	substr = malloc(actual_len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < actual_len)
	{
		substr[i] = s[start + i];
		i ++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	int	st;
	int	l;

	str = "okcomputer";
	st = 3;
	l = 5;

	printf("origin function: %s\n", substr(str, st, l));
	printf("dest funciont: %s\n", ft_substr(str, st, l));

	return (0);
}*/
