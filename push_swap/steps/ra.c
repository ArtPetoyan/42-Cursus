/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:35:50 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/09 22:35:51 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_m **stack)
{
	t_m	*node1;
	t_m	*node2;

	if (!(*stack))
		return ;
	node2 = *stack;
	node1 = *stack;
	while (node2->next)
		node2 = node2->next;
	*stack = node1->next;
	node1->next = NULL;
	node1->prev = node2;
	node2->next = node1;
	(*stack)->prev = NULL;
	write(1, "ra\n", 3);
}
