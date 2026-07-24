/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/24 17:11:00 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c, int print)
{
	t_node	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	if (print)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
		if (g_bench && g_bench->active)
		{
			if (c == 'a')
				g_bench->op_counts[0]++;
			else if (c == 'b')
				g_bench->op_counts[1]++;
			g_bench->total_ops++;
		}
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next ||
		!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
	if (print)
	{
		write(1, "ss", 2);
		write(1, "\n", 1);
		if (g_bench && g_bench->active)
		{
			g_bench->op_counts[2]++;
			g_bench->total_ops++;
		}
	}
}

void	push(t_stack *dest, t_stack *src, char c, int print)
{
	t_node	*temp;

	if (!src || !src->head)
		return ;
	temp = src->head;
	src->head = src->head->next;
	temp->next = dest->head;
	dest->head = temp;
	src->size--;
	dest->size++;
	if (print)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
		if (g_bench && g_bench->active)
		{
			if (c == 'a')
				g_bench->op_counts[3]++;
			else if (c == 'b')
				g_bench->op_counts[4]++;
			g_bench->total_ops++;
		}
	}
}

void	ft_handle_rotate_print(char c)
{
	if (g_bench && g_bench->active)
	{
		if (c == 'b')
			g_bench->op_counts[6]++;
		else
			g_bench->op_counts[5]++;
		g_bench->total_ops++;
	}
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
