/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:02:53 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 03:44:15 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	swap_long_arr(long *arr, long a, long b)
{
	long	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int
	merge_sort_small(long *arr, long left, long right)
{
	long	i;
	long	j;
	long	smallist_index;

	i = left;
	while (i < right)
	{
		smallist_index = i;
		j = i + 1;
		while (j <= right)
		{
			if (arr[smallist_index] > arr[j])
				smallist_index = j;
			j++;
		}
		swap_long_arr(arr, i, smallist_index);
		i++;
	}
	return (1);
}

int
	arr_dup(long **result, long *arr, long left, long right)
{
	long	new_len;
	long	i;

	new_len = right - left + 1;
	if (!m(result, sizeof(long) * new_len))
		return (0);
	i = 0;
	while (i < new_len)
	{
		(*result)[i] = arr[left + i];
		i++;
	}
	return (1);
}

int
	merge_sort2(long *arr, long *ch_left, long *ch_right, t_merge *c)
{
	c->lb = c->mid - c->left;
	c->rb = c->right - c->mid - 1;
	c->li = 0;
	c->ri = 0;
	if (!merge_sort(ch_left, 0, c->lb) || !merge_sort(ch_right, 0, c->rb))
	{
		safe_free(&ch_left);
		safe_free(&ch_right);
		return (0);
	}
	c->i = c->left - 1;
	while (++c->i <= c->right)
		if ((ch_left[c->li] < ch_right[c->ri] && c->li <= c->lb) ||
				c->ri > c->rb)
			arr[c->i] = ch_left[c->li++];
		else if ((ch_left[c->li] >= ch_right[c->ri] &&
				c->ri <= c->rb) || c->li > c->lb)
			arr[c->i] = ch_right[c->ri++];
	safe_free(&ch_left);
	safe_free(&ch_right);
	return (1);
}

int
	merge_sort(long *arr, long left, long right)
{
	long	mid;
	long	*ch_left;
	long	*ch_right;
	t_merge	c;

	ch_left = 0;
	ch_right = 0;
	if (right - left < 5)
		return (merge_sort_small(arr, left, right));
	mid = (right + left) / 2;
	if (!arr_dup(&ch_left, arr, left, mid))
		return (0);
	if (!arr_dup(&ch_right, arr, mid + 1, right))
	{
		safe_free(&ch_left);
		return (0);
	}
	c.mid = mid;
	c.left = left;
	c.right = right;
	return (merge_sort2(arr, ch_left, ch_right, &c));
}
