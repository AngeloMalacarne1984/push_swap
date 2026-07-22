/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/21 15:46:30 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	min_rank;
	int	max_rank;

	min_rank = 0;
	max_rank = chunk_size - 1;
	while (stack_a->size > 0)
	{
		if (stack_a->head->target_index <= max_rank)
		{
			push(stack_b, stack_a, 'b', 1);
			if (stack_b->head->target_index >= min_rank + (chunk_size / 2))
				rotate(stack_b, 'b', 1);
			if (stack_b->size == max_rank + 1)
			{
				min_rank += chunk_size;
				max_rank += chunk_size;
			}
		}
		else
			rotate(stack_a, 'a', 1);
	}
}

void	return_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int max_idx;

	while (stack_b->size > 0)
	{
		max_idx = get_max_index(stack_b);
		if (max_idx <= stack_b->size / 2)
		{
			while (max_idx-- > 0)
				rotate(stack_b, 'b', 1);
		}
		else
		{
			while (max_idx++ < stack_b->size)
				reverse_rotate(stack_b, 'b', 1);
		}
		push(stack_a, stack_b, 'a', 1);
	}
}

void	medium_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int chunk_size;

	if (bench->active)
	{
		bench->strategy_name = "Medium Sort (Chunks)";
		bench->complexity = "O(n*sqrt(n))";
	}
	if (!stack_a || !stack_b)
		return;
	index_stack(stack_a);// spaeter pruefen ob mit oder ohne &!
	if (stack_a->size < 50)
		chunk_size = integer_sqrt_small(stack_a->size);
	else
		chunk_size = integer_sqrt_small(stack_a->size) + 10;
	if (chunk_size < 1)
		chunk_size = 1;
	process_chunks(stack_a, stack_b, chunk_size);
	return_to_a(stack_a, stack_b);
}
