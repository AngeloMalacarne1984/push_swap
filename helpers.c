/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 03:59:29 by mlucka            #+#    #+#             */
/*   Updated: 2026/07/24 16:26:07 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

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

int	ft_parse_single_string(char *str, t_stack *stack_a)
{
	char	**split;
	int		count;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	count = count_split(split);
	if (!check_arguments(count, split) || !check_duplicates(count, split))
	{
		write(2, "Error\n", 6);
		free_split(split);
		return (0);
	}
	build_stack(count, stack_a, split);
	free_split(split);
	return (1);
}
