/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_hex_generic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:30:13 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:30:14 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*upchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i ++;
	}
	return (str);
}

int	ft_pf_handle_hex_generic(unsigned int num_hex, char up_low)
{
	char	*result;
	int		len;

	result = num_to_hex(num_hex);
	if (!result)
		return (-1);
	if (up_low == 'X')
		upchar(result);
	ft_putstr_fd(result, 1);
	len = ft_strlen(result);
	free(result);
	return (len);
}
