/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:18:16 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 02:25:53 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPES_H
# define PUSH_SWAP_TYPES_H

/*
** types
*/

typedef struct s_stack		t_stack;
typedef struct s_stack_item	t_stack_item;
typedef struct s_program	t_program;
typedef struct s_arr		t_arr;
typedef struct s_calc		t_calc;
typedef struct s_merge		t_merge;
typedef struct s_pvipt		t_pvipt;

struct	s_stack
{
	t_stack_item	*top;
	t_stack_item	*bot;
	long			len;
};

struct	s_stack_item
{
	t_stack_item	*next;
	t_stack_item	*prev;
	long			data;
};

struct	s_arr
{
	long	*ds;
	long	len;
};

struct	s_program
{
	t_stack	a;
	t_stack b;
	t_arr	arr;
	char	*input;
	long	input_next;
	int		called_rra;
	int		called_rrb;
	int		called_ra;
	int		called_rb;
	int		called_sa;
	int		called_sb;
};

struct	s_calc
{
	long	piv_low;
	long	piv_high;
	long	len3;
	long	len2;
	long	len1;
};

struct	s_merge
{
	long	li;
	long	ri;
	long	lb;
	long	rb;
	long	i;
	long	left;
	long	mid;
	long	right;
};

struct	s_pvipt
{
	long	min;
	long	max;
};

#endif
