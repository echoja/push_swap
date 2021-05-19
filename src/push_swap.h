/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:57:03 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/20 03:14:03 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include "push_swap_types.h"

int				m(void *target, size_t size);

void			safe_free(void *target);
void			free_program_and_exit(int code);

t_program		*program(void);

/*
** program()->a should be initialized
*/
void			init_sorted_arr_from_a(void);

void			push(t_stack *stack, t_stack_item *item);
t_stack_item	*pop(t_stack *stack);

void			write_chars(const char *chars);
void			write_error_chars(const char *chars);

void			parse_b(void);
t_arr			arr_from_stack(t_stack stack);

/*
** arr should be sorted!
*/
int				is_duplicated(t_arr arr);

/*
** 1. arr should be sorted
** 2. input.max should be greater than input.min
*/
void			get_appropriate_pivot
					(t_arr arr, long *small, long *big, t_pvipt input);
void			init_calc(t_calc *c, long min, long max);

int				push_new(t_stack *stack, long data);
int				pop_free(t_stack *stack, long *data);

void			sswap(t_stack *stack);
void			smove(t_stack *dest, t_stack *src);
void			srotate(t_stack *stack);
void			srrotate(t_stack *stack);

void			sa(void);
void			sb(void);
void			ss(void);
void			pa(void);
void			pb(void);
void			ra(void);
void			rb(void);
void			rr(void);
void			rrr(void);
void			rra(void);
void			rrb(void);

/*
** program()->arr should be prepared
*/
void			resolve_atop(long len, long min, long max);
void			resolve_btop(long len, long min, long max);
void			resolve_lazy(void);

/*
** test functions
*/

void			print_stack(t_stack stack);
void			print_arr(t_arr arr);
int				merge_sort(long *arr, long left, long right);

#endif
