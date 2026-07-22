/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/20 16:26:59 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int first = stack->head->value;
	int second = stack->head->next->value;
	int third = stack->head->next->next->value;

	if (first > second && second < third && first < third)
		swap(stack, 'a', 1);
	else if (first > second && second > third)
	{
		swap(stack, 'a', 1);
		reverse_rotate(stack, 'a', 1);
	}
	else if (first > second && second < third && first > third)
		rotate(stack, 'a', 1);
	else if (first < second && second > third && first < third)
	{
		swap(stack, 'a', 1);
		rotate(stack, 'a', 1);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(stack, 'a', 1);
}

void	move_min_to_top(t_stack *stack, char c)
{
	int min_pos = get_min_position(stack);
	
	if (min_pos <= stack->size / 2)
	{
		while (min_pos > 0)
		{
			rotate(stack, c, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack->size)
		{
			reverse_rotate(stack, c, 1);
			min_pos++;
		}
	}
}

void simple_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (bench->active)
	{
		bench->strategy_name = "Simple Sort";
		bench->complexity = "O(n^2)";
	}
	while (stack_a->size > 3)
	{
		move_min_to_top(stack_a, 'a');
		push(stack_b, stack_a, 'b', 1);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		push(stack_a, stack_b, 'a', 1);
	}
}
