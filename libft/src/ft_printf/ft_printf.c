/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:32:55 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:32:56 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_spe(const char form_s)
{
	char	*str_spe;

	str_spe = "cspdiuxX%";
	while (*str_spe)
	{
		if (form_s == *str_spe)
			return (1);
		else
			str_spe ++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && is_spe(*(str + 1)) == 1)
		{
			count += ft_printf_format(*(str + 1), args);
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str ++;
			count ++;
		}
	}
	va_end(args);
	return (count);
}
