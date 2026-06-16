/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/06/17 00:31:08 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c, bool print)
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
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, bool print)
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
	}
}

void	push(t_stack *dest, t_stack *src, char c, bool print)
{
	t_node	*temp;

	if (!src || !src->head)
		return ;
	temp = src->head;
	src->head = src->head->next;
	temp->next = dest->head;
	dest->head = temp;
	if (print)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack *stack, char c, bool print)
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

void	rr(t_stack *stack_a, t_stack *stack_b, bool print)
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

void	reverse_rotate(t_stack *stack, char c, bool print)
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
