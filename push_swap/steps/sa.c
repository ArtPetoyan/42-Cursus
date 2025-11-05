/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:36:22 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/09 22:36:23 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_m **stack)
{
	t_m	*node1;
	t_m	*node2;

	if (!(*stack) || !stack)
		return ;
	node1 = *stack;
	node2 = (*stack)->next;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	node1->next->prev = node2->next;
	*stack = node2;
	write(1, "sa\n", 3);
}
