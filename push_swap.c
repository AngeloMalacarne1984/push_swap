/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:35:47 by mlucka            #+#    #+#             */
/*   Updated: 2026/07/21 16:04:21 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stacks_and_bench(t_stack *stack_b, t_bench *bench)
{
	stack_b->head = NULL;
	stack_b->size = 0;
	bench->active = false;
	bench->strategy_name = NULL;
	bench->complexity = NULL;
}

static int	ft_parse_single_arg(char *arg, t_stack *stack_a)
{
	char	**split;
	int		count;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	count = count_split(split);
	if (!check_arguments(count, split) || !check_duplicates(count, split))
	{
		write(2, "Error\n", 6);
		free_split(split);
		return (0);
	}
	build_stack(count, stack_a, split);
	free_split(split);
	return (1);
}

static int	ft_parse_multiple_args(int argc, char **argv, t_stack *stack_a)
{
	if (!check_arguments(argc - 1, &argv[1]) || !check_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	build_stack(argc - 1, stack_a, &argv[1]);
	return (1);
}

static void	ft_execute_strategy(t_stack *stack_a, t_stack *stack_b, t_bench *bench, int argc, char **argv)
{
	if (has_flag(argc, argv, "--bench"))
		bench->active = true;
	if (has_flag(argc, argv, "--simple"))
	{
		bench->strategy_name = "Simple Sort";
		bench->complexity = "O(n^2)";
		simple_sort(stack_a, stack_b, bench);
	}
	else if (has_flag(argc, argv, "--medium"))
	{
		bench->strategy_name = "Medium Sort";
		bench->complexity = "O(n sqrt(n))";
		medium_sort(stack_a, stack_b, bench);
	}
	else if (has_flag(argc, argv, "--complex"))
	{
		bench->strategy_name = "Complex Sort (Radix)";
		bench->complexity = "O(n log n)";
		complex_sort(stack_a, stack_b);
	}
	else if (has_flag(argc, argv, "--adaptive") || 1)
		run_adaptive_strategy(&stack_a, &stack_b, &bench);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_bench	bench;

	if (argc < 2)
		return (0);
	ft_init_stacks_and_bench(&stack_b, &bench);
	if (argc == 2)
	{
		if (!ft_parse_single_arg(argv[1], &stack_a))
			return (1);
	}
	else
	{
		if (!ft_parse_multiple_args(argc, argv, &stack_a))
			return (1);
	}
	ft_execute_strategy(&stack_a, &stack_b, &bench, argc, argv);
	return (0);
}
