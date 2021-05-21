/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:15:06 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/21 22:15:13 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	sswap(t_stack *stack)
{
	t_stack_item	*second;
	long			swap_temp;

	if (stack->len <= 1)
		return ;
	second = stack->top->prev;
	swap_temp = second->data;
	second->data = stack->top->data;
	stack->top->data = swap_temp;
}

void
	smove(t_stack *dest, t_stack *src)
{
	t_stack_item	*moving;

	if (src->len == 0)
		return ;
	moving = pop(src);
	push(dest, moving);
}

void
	srotate(t_stack *stack)
{
	if (stack->len == 0)
		return ;
	stack->top = stack->top->prev;
	stack->bot = stack->bot->prev;
}

void
	srrotate(t_stack *stack)
{
	if (stack->len == 0)
		return ;
	stack->top = stack->top->next;
	stack->bot = stack->bot->next;
}
