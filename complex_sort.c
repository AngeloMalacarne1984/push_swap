/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/06/25 15:53:39 by amalacar         ###   ########.fr       */
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

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int j;
	int max_bits;

	if (!stack_a || stack_a->size < 2)
		return ;
	index_stack(stack_a);//& ja oder nein spaeter
	max_bits = 0;
	while ((stack_a->size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = stack_a->size;
		while (j--)
		{
			if (!((stack_a->head->target_index >> i) & 1))
				push(stack_b, stack_a, 'b', 1); // Bit ist 0 -> zu Stack B
			else
				rotate(stack_a, 'a', 1);       // Bit ist 1 -> behalten
		}
		while (stack_b->size > 0)
			push(stack_a, stack_b, 'a', 1);
	}
}
