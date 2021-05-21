/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:39:36 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 03:42:44 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	check_num(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int
	check_line(int len, const char *b)
{
	if ((len == 2 && (
			(b[0] == 'p' && (b[1] == 'a' || b[1] == 'b')) ||
			(b[0] == 's' && (b[1] == 'a' || b[1] == 'b' || b[1] == 's')) ||
			(b[0] == 'r' && (b[1] == 'a' || b[1] == 'b' || b[1] == 'r')))) ||
		(len == 3 && b[0] == 'r' && b[1] == 'r' &&
			(b[2] == 'a' || b[2] == 'b' || b[2] == 'r')))
		return (1);
	return (0);
}

int
	check_sorted(void)
{
	long			i;
	long			ordered_count;
	t_stack_item	*item;

	i = 0;
	ordered_count = 0;
	item = program()->a.top;
	while (i < program()->a.len - 1)
	{
		if (item->data < item->prev->data)
			ordered_count++;
		item = item->prev;
		i++;
	}
	if (ordered_count == program()->a.len - 1)
		return (1);
	return (0);
}
