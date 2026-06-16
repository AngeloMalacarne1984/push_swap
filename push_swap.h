/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/06/13 15:49:40 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // read, write
# include "../libft/libft.h" // ft_printf
# include <stdbool.h> // for datatype bool
# include <limits.h> // INT_MAX, INT_MIN
# include <stdint.h> // int32_t

typedef struct s_stack
{
	t_node			*head;
	int				size;
}	t_stack;

// Operations
void	swap(t_stack *stack, char c, bool print);
void	push(t_stack *src, t_stack *dest, char c, bool print);
void	rotate(t_stack *stack, char c, bool print);
void	reverse_rotate(t_stack *stack, char c, bool print);

#endif