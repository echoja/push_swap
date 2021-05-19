/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:51:39 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:49:27 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser/parser.h"

long
	get_strlen(const char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

int	check_num(const char *str)
{
	int		i;

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

long
	chars_to_long(const char *s)
{
	t_ul		i;
	int			minus;
	long		result;

	result = 0;
	minus = 1;
	i = 0;
	if (s[0] == '-')
	{
		minus = -1;
		i = 1;
	}
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * minus);
}

int
	main(int argc, char *argv[])
{
	int		i;
	long	num;

	if (argc == 2)
	{
		program()->input = argv[1];
		parse_b();
		i = -1;
		num = program()->b.len;
		while (++i < num)
			smove(&program()->a, &program()->b);
		init_sorted_arr_from_a();
		resolve_atop(program()->a.len, LONG_MIN, LONG_MAX);
	}
	else if (argc >= 3)
	{
		i = 1;
		while (i < argc)
		{
			if (!check_num(argv[i]))
				return (1); // todo: error message
			num = chars_to_long(argv[i]);
			if (num >= INT_MAX)
				return (1); // todo: error message
			push_new(&program()->b, chars_to_long(argv[i]));
			i++;
		}
		i = -1;
		num = program()->b.len;
		while (++i < num)
			smove(&program()->a, &program()->b);
		init_sorted_arr_from_a();
		resolve_atop(program()->a.len, LONG_MIN, LONG_MAX);
	}
	resolve_lazy();
	// print_stack(program()->a);
}
