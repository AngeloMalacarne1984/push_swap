/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/06/23 16:28:50 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *stack, int *arr)
{
	t_node	*curr;
	int		i;

	curr = stack->head;
	while (curr)
	{
		i = 0;
		while (i < stack->size)
		{
			if (curr->value == arr[i])
			{
				curr->target_index = i;
				break;
			}
			i++;
		}
		curr = curr->next;
	}
}

void	index_stack(t_stack *stack)
{
	int		*arr;
	int		i;
	t_node	*curr;

	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		return;
	curr = stack->head;
	i = 0;
	while (curr)
	{
		arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
	sort_array(arr, stack->size);
	assign_indices(stack, arr);
	free(arr);
}

void	process_chunks(t_stack *stack_a, t_stack *stack_b, int size, int chunk_size)
{
	int	min_rank;
	int	max_rank;

	int	min_rank = 0;
	int	max_rank = chunk_size - 1;
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

void	medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	int chunk_size;

	if (!stack_a || !stack_b)
		return;
	index_stack(stack_a);// spaeter pruefen ob mit oder ohne &!
	chunk = integer_sqrt_small(stack_a->size) - 1;
	if (chunk_size < 1)
		chunk_size = 1;
	process_chunks(stack_a, stack_b, stack_a->size, chunk_size);
	return_to_a(a, b);
}
