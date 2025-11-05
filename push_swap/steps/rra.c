/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:36:06 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/09 22:36:07 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_m **stack)
{
	t_m	*node1;
	t_m	*node2;

	if (!(*stack) || !((*stack)->next))
		return ;
	node2 = *stack;
	node1 = *stack;
	while (node2->next)
		node2 = node2->next;
	node2->prev-> next = NULL;
	node2->prev = NULL;
	node2->next = node1;
	*stack = node2;
	node1->prev = *stack;
	write(1, "rra\n", 4);
}
