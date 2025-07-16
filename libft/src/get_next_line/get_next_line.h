/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:33:18 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:19 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include "../../libft.h"
# include <stdlib.h>

char	*get_next_line(int fd);
char	*copy_buffer(char *readline, char *buffer);
char	*extra_line(char *readline);
char	*update_readline(char *readline);

#endif
