#include "src/push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>


void print_stack(t_stack stack)
{
	t_stack_item *t = stack.bot;
	if (stack.len == 0)
	{
		printf("empty\n");
		return ;
	}
	printf("bot  |");
	while (1)
	{
		printf("%ld", t->data);
		if (t->next != stack.bot)
			printf(" ");
		t = t->next;
		if (t == stack.bot)
			break;
	}
	printf("|  top\n");
}

void print_arr(t_arr arr)
{
	printf("|");
	for(int i = 0; i < arr.len ; i++)
	{
		printf("%ld", arr.ds[i]);
		if (i != arr.len - 1)
			printf(" ");
	}
	printf("|\n");
}

void test_push_new(void)
{
	push_new(&program()->a, 1);
	push_new(&program()->a, 3);
	push_new(&program()->a, 6);
	push_new(&program()->a, 7);
	push_new(&program()->a, 9);
	print_stack(program()->a);
}
void test_pop_free(void)
{
	long d;

	push_new(&program()->a, 1);
	push_new(&program()->a, 3);
	push_new(&program()->a, 6);
	push_new(&program()->a, 7);
	push_new(&program()->a, 9);
	pop_free(&program()->a, &d);
	pop_free(&program()->a, &d);
	pop_free(&program()->a, &d);
	pop_free(&program()->a, &d);
	// pop_free(&program()->a, &d);
	print_stack(program()->a);

}

void test_smove(void)
{
		// long d;

	push_new(&program()->a, 1);
	push_new(&program()->a, 3);
	push_new(&program()->a, 6);
	push_new(&program()->a, 7);
	push_new(&program()->a, 9);
	smove(&program()->b, &program()->a);
	smove(&program()->b, &program()->a);
	smove(&program()->b, &program()->a);
	print_stack(program()->a);
	print_stack(program()->b);
}

void test_sswap(void)
{
	push_new(&program()->a, 1);
	push_new(&program()->a, 3);
	push_new(&program()->a, 6);
	push_new(&program()->a, 7);
	push_new(&program()->a, 9);
	print_stack(program()->a);
	sswap(&program()->a);
	print_stack(program()->a);
	sswap(&program()->b);
	print_stack(program()->b);

}

void test_srotate(void)
{
	push_new(&program()->a, 1);
	push_new(&program()->a, 3);
	push_new(&program()->a, 6);
	push_new(&program()->a, 7);
	push_new(&program()->a, 9);
	srotate(&program()->a);
	srotate(&program()->a);
	print_stack(program()->a);

}

void test_srrotate(void)
{
	push_new(&program()->a, 1);
	push_new(&program()->a, 3);
	push_new(&program()->a, 6);
	push_new(&program()->a, 7);
	push_new(&program()->a, 9);
	srrotate(&program()->a);
	srrotate(&program()->a);
	print_stack(program()->a);

}

void test_op(void)
{
	push_new(&program()->a, 8);
	push_new(&program()->a, 5);
	push_new(&program()->a, 6);
	push_new(&program()->a, 3);
	push_new(&program()->a, 1);
	push_new(&program()->a, 2);
	sa();
	// print_stack(program()->a);
	pb();
	pb();
	pb();
	// print_stack(program()->a);
	// print_stack(program()->b);
	// ra();
	// rb();
	rr();
	rrr();
	sa();
	pa();
	pa();
	pa();
	print_stack(program()->a);
	print_stack(program()->b);
}

void test_resolve_atop_input(void)
{
	parse_b();
	init_sorted_arr_from_a();
	resolve_atop(program()->a.len, LONG_MIN, LONG_MAX);
	print_stack(program()->a);
	print_stack(program()->b);
}

void test_resolve_atop(void)
{
	push_new(&program()->a, 1);
	push_new(&program()->a, 2);
	push_new(&program()->a, 3);
	push_new(&program()->a, 11);
	push_new(&program()->a, 5);
	push_new(&program()->a, 13);
	push_new(&program()->a, 12);
	push_new(&program()->a, 6);
	push_new(&program()->a, 4);
	push_new(&program()->a, 14);
	push_new(&program()->a, 9);
	push_new(&program()->a, 8);
	push_new(&program()->a, 7);
	push_new(&program()->a, 10);
	init_sorted_arr_from_a();
	resolve_atop(program()->a.len, LONG_MIN, LONG_MAX);
	print_stack(program()->a);
	print_stack(program()->b);
}

void test_parser(void)
{
	parse_b();
	print_stack(program()->a);
	t_arr arr = arr_from_stack(program()->a);
	print_arr(arr);
	safe_free(&arr.ds);

}

void test_merge_sort(void)
{
	long ds[20] = {5, 2, 1, 1, 7, 4, 4, 4, 4, 3, 1, 10, 10, 10, 10, 9, 8, 6, 0, 9};
	t_arr arr;
	arr.ds = ds;
	arr.len = 20;
	merge_sort(arr.ds, 0, 19);
	print_arr(arr);
}

void test_get_appropriate_pivot(void)
{
	long ds[20] = {5, 2, 1, 1, 7, 4, 4, 4, 4, 3, 1, 10, 10, 10, 10, 9, 8, 6, 0, 9};
	t_arr arr;
	arr.ds = ds;
	arr.len = 20;
	merge_sort(arr.ds, 0, 19);
	long small, big;
	t_pvipt input;
	input.max = LONG_MAX;
	input.min = LONG_MIN;
	get_appropriate_pivot(arr, &small, &big, input);
	printf("%ld %ld\n", small, big);
	input.max = 10;
	input.min = 2;
	get_appropriate_pivot(arr, &small, &big, input);
	printf("%ld %ld\n", small, big);
	print_arr(arr);
}

void test_sorted_arr_from_a(void)
{
	// char *c = "1 23 4 54 54 54 52 4123 1 2 3 4 5 6 \n";
	// write(0, c, strlen(c));
	parse_b();
	init_sorted_arr_from_a();
	print_arr(program()->arr);
}

void test_duplicated(void)
{
	parse_b();
	init_sorted_arr_from_a();
	printf("duplicated: %d\n", is_duplicated(program()->arr));
	// print_arr(program()->arr);
}

void test_resolve_btop3(void)
{
	push_new(&program()->a, 1234);
	push_new(&program()->a, 1234);
	push_new(&program()->a, 1234);
	push_new(&program()->b, 1);
	push_new(&program()->b, 2);
	push_new(&program()->b, 3);
	resolve_btop(3, LONG_MIN, LONG_MAX);
	push_new(&program()->b, 1);
	push_new(&program()->b, 3);
	push_new(&program()->b, 2);
	resolve_btop(3, LONG_MIN, LONG_MAX);
	push_new(&program()->b, 2);
	push_new(&program()->b, 1);
	push_new(&program()->b, 3);
	resolve_btop(3, LONG_MIN, LONG_MAX);
	push_new(&program()->b, 2);
	push_new(&program()->b, 3);
	push_new(&program()->b, 1);
	resolve_btop(3, LONG_MIN, LONG_MAX);
	push_new(&program()->b, 3);
	push_new(&program()->b, 1);
	push_new(&program()->b, 2);
	resolve_btop(3, LONG_MIN, LONG_MAX);
	push_new(&program()->b, 3);
	push_new(&program()->b, 2);
	push_new(&program()->b, 1);
	resolve_btop(3, LONG_MIN, LONG_MAX);
	print_stack(program()->a);
}
// int main(void)
// {
// 	// test_push_new();
// 	// test_pop_free();
// 	// test_smove();
// 	// test_sswap();
// 	// test_srotate();
// 	// test_srrotate();
// 	// test_op();
// 	// test_resolve_atop();
// 	test_resolve_atop_input();
// 	// test_parser();
// 	// test_merge_sort();
// 	// test_get_appropriate_pivot();
// 	// test_sorted_arr_from_a();
// 	// test_resolve_btop3();
// 	// test_duplicated();
// 	// while(1);
// }
