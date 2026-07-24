/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/24 16:19:49 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder_value(t_stack *stack_a)
{
	double	disorder;
	long	int_part;
	long	dec_part;

	disorder = calculate_disorder(stack_a) * 100.0;
	int_part = (long)disorder;
	dec_part = (long)((disorder - int_part) * 100);
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putstr_fd(".", 2);
	if (dec_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(dec_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_disorder_and_strategy(t_stack *stack_a, t_bench *bench)
{
	print_disorder_value(stack_a);
	ft_putstr_fd("Strategy: ", 2);
	if (bench->strategy_name)
		ft_putstr_fd(bench->strategy_name, 2);
	else
		ft_putstr_fd("Adaptive", 2);
	ft_putstr_fd(" (Complexity: ", 2);
	if (bench->complexity)
		ft_putstr_fd(bench->complexity, 2);
	else
		ft_putstr_fd("Unknown", 2);
	ft_putstr_fd(")\n", 2);
}

static void	print_operation_counts(int *op_counts)
{
	char	*names[11];
	int		i;

	names[0] = "sa: ";
	names[1] = "sb: ";
	names[2] = "ss: ";
	names[3] = "pa: ";
	names[4] = "pb: ";
	names[5] = "ra: ";
	names[6] = "rb: ";
	names[7] = "rr: ";
	names[8] = "rra: ";
	names[9] = "rrb: ";
	names[10] = "rrr: ";
	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(names[i], 2);
		ft_putnbr_fd(op_counts[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

void	print_benchmark(t_stack *stack_a, t_bench *bench, int total_ops, int *op_counts)
{
	if (!bench->active)
		return ;
	print_disorder_and_strategy(stack_a, bench);
	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_operation_counts(op_counts);
}
