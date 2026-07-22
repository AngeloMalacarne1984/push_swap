/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/20 15:17:33 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char c, int print)
{
	t_node	*first;
	t_node	*last;
	
	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	stack->head = stack->head->next;
	last = stack->head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	if (print)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	if (print)
	{
		write(1, "rr", 2);
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_stack *stack, char c, int print)
{
	t_node	*first;
	t_node	*onelast;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	onelast = stack->head;
	while (onelast->next->next != NULL)
	{
		onelast = onelast->next;
	}
	first = onelast->next;
	onelast->next = NULL;
	first->next = stack->head;
	stack->head = first;
	if (print)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
	if (print)
	{
		write(1, "rrr", 3);
		write(1, "\n", 1);
	}
}
