/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:35:47 by mlucka            #+#    #+#             */
/*   Updated: 2026/07/24 16:25:55 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse_args(int argc, char **argv, t_stack *stack_a, int *start)
{
	*start = 1;
	while (*start < argc && argv[*start][0] == '-')
		(*start)++;
	if (argc - *start == 1)
		return (ft_parse_single_string(argv[*start], stack_a));
	if (argc - *start < 1)
		return (0);
	if (!check_arguments(argc - *start, &argv[*start])
		|| !check_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	build_stack(argc - *start, stack_a, &argv[*start]);
	return (1);
}

static void	ft_parse_single_flag(char *arg, t_bench *bench)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		bench->active = 1;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
	{
		bench->strategy_name = "Simple Sort";
		bench->complexity = "O(n^2)";
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		bench->strategy_name = "Medium Sort";
		bench->complexity = "O(n sqrt(n))";
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		bench->strategy_name = "Complex Sort (Radix)";
		bench->complexity = "O(n log n)";
	}
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		bench->strategy_name = "Adaptive";
}

static void	ft_check_flags(int argc, char **argv, t_bench *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		ft_parse_single_flag(argv[i], bench);
		i++;
	}
}

static void	ft_execute_strategy(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int	op_counts[11] = {0};
	int	total_ops;

	if (bench->strategy_name && ft_strncmp(bench->strategy_name, "Simple Sort", 11) == 0)
		simple_sort(stack_a, stack_b, bench);
	else if (bench->strategy_name && ft_strncmp(bench->strategy_name, "Medium Sort", 11) == 0)
		medium_sort(stack_a, stack_b, bench);
	else if (bench->strategy_name && ft_strncmp(bench->strategy_name, "Complex Sort", 12) == 0)
		complex_sort(stack_a, stack_b);
	else
		run_adaptive_strategy(&stack_a, &stack_b, bench);
	total_ops = 0;
	print_benchmark(stack_a, bench, total_ops, op_counts);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_bench	bench;
	int		start;

	if (argc < 2)
		return (0);
	stack_b.head = NULL;
	stack_b.size = 0;
	bench.active = 0;
	bench.strategy_name = NULL;
	bench.complexity = NULL;
	ft_check_flags(argc, argv, &bench);
	if (!ft_parse_args(argc, argv, &stack_a, &start))
		return (1);
	ft_execute_strategy(&stack_a, &stack_b, &bench);
	return (0);
}
