/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:34:02 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/21 05:44:16 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	stack_push(t_stack *stack, int x, int y)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->x = x;
	new_node->y = y;
	new_node->next = stack->top;
	stack->top = new_node;
}

int	stack_pop(t_stack *stack, int *x, int *y)
{
	t_stack_node	*top_node;

	if (stack_is_empty(stack))
		return (0);
	top_node = stack->top;
	*x = top_node->x;
	*y = top_node->y;
	stack->top = top_node->next;
	free(top_node);
	return (1);
}

void	stack_free(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->top = NULL;
}
