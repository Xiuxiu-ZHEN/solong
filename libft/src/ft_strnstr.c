/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:50 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:51 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while ((i + j) < len && haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j ++;
		}
		i ++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*hay;
	char	*nee;
	char	*ft;
	int	len;

	len = 9;
	hay = "oooookcomputer";
	nee = "com";
	ft = ft_strnstr(hay, nee, len);
	if (len > 0)
		printf("%ld\n", ft - hay);
	else
		printf("len < 0\n");
	return (0);
}*/
