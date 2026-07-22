/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:13:56 by mlucka            #+#    #+#             */
/*   Updated: 2026/07/21 15:13:40 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (stack->head == NULL)
	{
		stack->head = new_node;
		return ;
	}
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	build_stack(int argc, t_stack *stack, char **argv)
{
	int		i;
	t_node	*new_node;

	stack->head = NULL;
	stack->size = 0;
	i = 0;
	while (i < argc)
	{
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
			return ;
		add_back(stack, new_node);
		stack->size++;
		i++;
	}
}
