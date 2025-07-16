/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:36 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:37 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <unistd.h>
int	main(void)
{
	int	c;

	c = '7';
	if (ft_isdigit(c) == 1)
		write(1, "it is a number.\n", 16);
	else
		write(1, "it is not a number.\n", 20);
	return (0);
}*/
