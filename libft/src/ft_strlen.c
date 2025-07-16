/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:34:43 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:34:44 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*str;

	str = "just do it.";
	printf("lenth of string : %d\n", ft_strlen(str));
	return (0);
}*/
