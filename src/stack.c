/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:59:03 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/21 22:21:12 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	push_new(t_stack *stack, long data)
{
	t_stack_item	*allocated;

	if (!m(&allocated, sizeof(t_stack_item)))
		return (0);
	allocated->data = data;
	push(stack, allocated);
	return (1);
}

int
	pop_free(t_stack *stack, long *data)
{
	t_stack_item	*item;

	item = pop(stack);
	if (!item)
		return (0);
	*data = item->data;
	safe_free(&item);
	return (1);
}

t_stack_item
	*pop(t_stack *stack)
{
	t_stack_item	*item;

	if (stack->len == 0)
		return (0);
	item = stack->top;
	if (stack->len == 1)
	{
		stack->top = 0;
		stack->bot = 0;
		stack->len = 0;
		return (item);
	}
	stack->top = stack->top->prev;
	stack->top->next = stack->bot;
	stack->bot->prev = stack->top;
	stack->len -= 1;
	return (item);
}

void
	push(t_stack *stack, t_stack_item *item)
{
	if (stack->len == 0)
	{
		item->prev = item;
		item->next = item;
		stack->top = item;
		stack->bot = item;
		stack->len = 1;
		return ;
	}
	item->prev = stack->top;
	item->next = stack->bot;
	stack->top->next = item;
	stack->bot->prev = item;
	stack->top = item;
	stack->len += 1;
}
