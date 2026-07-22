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
