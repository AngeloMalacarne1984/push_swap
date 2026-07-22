/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/20 15:03:15 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	integer_sqrt_small(int number)
{
int	low;
int	high;
int	result;
int mid;

if (number < 0)
	return -1;
low = 0;
high = number;
result = 0;
while (low <= high)
{
	mid = low + (high - low) / 2;
	if (mid * mid <= number)
	{
		result = mid;
		low = mid + 1;
	}
	else
		high = mid - 1;
}
return result;
}

int	get_min_position(t_stack *stack)
{
	t_node *curr = stack->head;
	int min_val = curr->value;
	int min_pos = 0;
	int pos = 0;

	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

int	get_max_index(t_stack *stack)
{
	t_node *curr = stack->head;
	int max_val = -1;
	int max_pos = 0;
	int pos = 0;

	while (curr)
	{
		if (curr->target_index > max_val)
		{
			max_val = curr->target_index;
			max_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (max_pos);
}

void	move_min_to_top(t_stack *stack, char c)// kann man ecvtl loeschen
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

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
