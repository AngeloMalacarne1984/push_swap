/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/24 17:11:01 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_handle_rev_rotate_print(char c)
{
	if (g_bench && g_bench->active)
	{
		if (c == 'b')
			g_bench->op_counts[9]++;
		else
			g_bench->op_counts[8]++;
		g_bench->total_ops++;
	}
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, char c, int print)
{
	t_node	*first;
	t_node	*last;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	stack->head = first->next;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_handle_rotate_print(c);
}

void	reverse_rotate(t_stack *stack, char c, int print)
{
	t_node	*first;
	t_node	*onelast;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	onelast = stack->head;
	while (onelast->next && onelast->next->next)
		onelast = onelast->next;
	first = onelast->next;
	onelast->next = NULL;
	first->next = stack->head;
	stack->head = first;
	if (print)
		ft_handle_rev_rotate_print(c);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	if (print && g_bench && g_bench->active)
	{
		g_bench->op_counts[7]++;
		g_bench->total_ops++;
	}
	if (print)
		write(1, "rr\n", 3);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
	if (print && g_bench && g_bench->active)
	{
		g_bench->op_counts[10]++;
		g_bench->total_ops++;
	}
	if (print)
		write(1, "rrr\n", 4);
}
