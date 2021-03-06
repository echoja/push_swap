/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:57:03 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 03:44:01 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <limits.h>
# include "push_swap_types.h"

# define READ_BUF_SIZE 1024

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

int				parse_b(void);
t_arr			arr_from_stack(t_stack stack);
int				check_sorted(void);
int				check_num(const char *str);
int				check_line(int len, const char *b);
void			preprocess(int argc, char *argv[]);
int				merge_sort(long *arr, long left, long right);

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
long			get_strlen(const char *str);

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
void			resolve_atop_divide_loop(t_stack_item *comp, t_calc *c);
void			resolve_atop_divide(long len, t_calc *c);
void			resolve_atop_move(t_calc c);
void			resolve_small_b3(long d1, long d2, long d3);
void			resolve_small_b(long len, t_stack_item *top);
void			resolve_atop3_exact(long d1, long d2, long d3);
void			resolve_atop3(t_stack_item *top, t_calc c);
void			resolve_btop(long len, long min, long max);
void			resolve_lazy(void);

/*
** test functions
*/

void			print_stack(t_stack stack);
void			print_arr(t_arr arr);

#endif
