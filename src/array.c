/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:35:44 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 03:14:27 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr
	arr_from_stack(t_stack stack)
{
	t_arr			arr;
	long			i;
	t_stack_item	*item;

	m(&arr.ds, sizeof(long) * stack.len);
	if (!arr.ds)
	{
		arr.len = 0;
		arr.ds = 0;
		return (arr);
	}
	arr.len = stack.len;
	item = stack.bot;
	i = 0;
	while (i < stack.len)
	{
		arr.ds[i] = item->data;
		item = item->next;
		i++;
	}
	return (arr);
}

void
	init_sorted_arr_from_a(void)
{
	long	len;

	len = program()->a.len;
	if (len == 0)
		return ;
	program()->arr = arr_from_stack(program()->a);
	if (program()->arr.ds == 0)
		free_program_and_exit(1);
	merge_sort(program()->arr.ds, 0, len - 1);
}
