/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:51:39 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/22 03:18:11 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "parser/parser.h"

int
	main(int argc, char *argv[])
{
	preprocess(argc, argv);
	program()->op_echo = 1;
	if (check_sorted())
		free_program_and_exit(0);
	resolve_atop(program()->a.len, LONG_MIN, LONG_MAX);
	resolve_lazy();
	free_program_and_exit(0);
	return (0);
}
