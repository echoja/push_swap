/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:57:03 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:48:52 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <limits.h>



/** types **/

typedef struct s_stack		t_stack;
typedef struct s_stack_item	t_stack_item;
typedef struct s_program	t_program;
typedef struct s_arr		t_arr;
typedef struct s_calc		t_calc;
typedef struct s_merge		t_merge;
typedef struct s_pvipt		t_pvipt;

struct s_stack
{
	t_stack_item	*top;
	t_stack_item	*bot;
	long			len;
};

struct s_stack_item
{
	t_stack_item	*next;
	t_stack_item	*prev;
	long			data;
};

struct s_arr
{
	long	*ds;
	long	len;
};

struct s_program
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

struct s_calc
{
	long	piv_low;
	long	piv_high;
	long	len3;
	long	len2;
	long	len1;
};

struct s_merge
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

struct s_pvipt
{
	long	min;
	long	max;
};

int
	m(void *target, size_t size);
void
	safe_free(void *target);
t_program
	*program(void);

/** program()->a should be initialized */
void
	init_sorted_arr_from_a(void);

void
	push(t_stack *stack, t_stack_item *item);
t_stack_item *
	pop(t_stack *stack);


void
	parse_b(void);
t_arr
	arr_from_stack(t_stack stack);

/** arr should be sorted! */
int
	is_duplicated(t_arr arr);



/**
 * 1. arr should be sorted
 * 2. input.max should be greater than input.min
 */
void
	get_appropriate_pivot(t_arr arr, long *small, long* big, t_pvipt input);

int
	push_new(t_stack *stack, long data);
int
	pop_free(t_stack *stack, long *data);

void
	sswap(t_stack *stack);
void
	smove(t_stack *dest, t_stack *src);
void
	srotate(t_stack *stack);
void
	srrotate(t_stack *stack);

void
	sa(void);
void
	sb(void);
void
	ss(void);
void
	pa(void);
void
	pb(void);
void
	ra(void);
void
	rb(void);
void
	rr(void);
void
	rrr(void);
void
	rra(void);
void
	rrb(void);

/**
 * program()->arr should be prepared
 */
void
	resolve_atop(long len, long min, long max);
void
	resolve_btop(long len, long min, long max);
void
	resolve_lazy(void);

/** test functions **/
void
	print_stack(t_stack stack);
void
	print_arr(t_arr arr);
int
	merge_sort(long *arr, long left, long right);

#endif
