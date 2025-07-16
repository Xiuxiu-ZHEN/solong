/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:29 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:30 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
/*
#include <unistd.h>
int	main(void)
{
	int	c;

	c = 'a';
	if (ft_isalnum(c))
		write(1, "it is num or alpha\n", 19);
	else
		write(1, "it is neither num nor alpha\n", 28);
	return (0);
}*/
