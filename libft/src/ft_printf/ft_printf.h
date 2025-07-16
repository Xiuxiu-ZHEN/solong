/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:32:59 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:00 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>
# include <stdint.h>

char	*num_to_hex(uintptr_t num);
int		ft_printf(const char *str, ...);
int		ft_printf_format(char spe, va_list args);
int		ft_pf_handle_unsigned_int(unsigned int n);
int		ft_pf_handle_int(int n);
int		ft_pf_handle_str(char *str);
int		ft_pf_handle_pointer(void *ptr);
int		ft_pf_handle_hex_generic(unsigned int num_hex, char up_low);

#endif
