/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:22 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/21 00:55:08 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	offspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i ++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	b;
	int	output;

	i = offspace(str);
	b = 1;
	output = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + (str[i] - '0');
		i ++;
	}
	return (b * output);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s;
	int	origin;
	int	ft;

	s = "+22";
	origin = atoi(s);
	ft = ft_atoi(s);
	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}*/
