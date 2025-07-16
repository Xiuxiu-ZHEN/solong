/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:31:45 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:31:46 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_handle_pointer(void *ptr)
{
	char		*adresse;
	char		*hex_str;
	int			len;
	const char	*begin_adresse;

	begin_adresse = "0x";
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	hex_str = num_to_hex((uintptr_t)ptr);
	adresse = ft_strjoin(begin_adresse, hex_str);
	free(hex_str);
	if (!adresse)
		return (-1);
	ft_putstr_fd(adresse, 1);
	len = ft_strlen(adresse);
	free(adresse);
	return (len);
}
