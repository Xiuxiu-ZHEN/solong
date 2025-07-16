/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:32:53 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:32:53 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(char spe, va_list args)
{
	if (spe == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (spe == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	if (spe == 'd' || spe == 'i')
		return (ft_pf_handle_int(va_arg(args, int)));
	if (spe == 'u')
		return (ft_pf_handle_unsigned_int(va_arg(args, unsigned int)));
	if (spe == 'p')
		return (ft_pf_handle_pointer(va_arg(args, void *)));
	if (spe == 's')
		return (ft_pf_handle_str(va_arg(args, char *)));
	if (spe == 'x' || spe == 'X')
		return (ft_pf_handle_hex_generic(va_arg(args, unsigned int), spe));
	return (0);
}
