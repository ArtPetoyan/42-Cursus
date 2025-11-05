/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:33:11 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/12 16:51:50 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print2(t_m **a, t_m *b)
{
	if ((*a)->index > b->index)
		rra(a);
}

static void	print3(t_m **a, t_m *b)
{
	if ((*a)->index == 0 && b->index == 1)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->index == 1)
	{
		if ((*a)->next->index == 0)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if ((*a)->next->index == 0)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

static void	print4(t_m **a, t_m *b, t_m **bb)
{
	b = *a;
	if ((*a)->next->next->next->index == 3)
	{
		rra(a);
		pb(bb, a);
	}
	else
	{
		while ((*a)->next->next->next->index != 3)
		{
			if (b->index == 3)
			{
				pb(bb, a);
				break ;
			}
			b = b->next;
			ra(a);
		}
	}
	if (!sorted(*a))
		print3(a, (*a)->next->next);
	pa (a, bb);
	ra (a);
}

static void	print5(t_m **a, t_m *b, t_m **bb)
{
	int	count;

	count = 0;
	b = *a;
	while (b->index != 4)
	{
		b = b->next;
		count++;
	}
	b = *a;
	if (count > 2)
		while (++count != 6)
			rra(a);
	else
		while (--count != -1)
			ra(a);
	pb(bb, a);
	if (!sorted(*a))
		print4(a, (*a)->next->next->next, bb);
	pa(a, bb);
	ra(a);
}

void	my_p(t_m **a, t_m **b, int i)
{
	if (i == 2)
		print2(a, (*a)->next);
	else if (i == 3)
		print3(a, (*a)->next->next);
	else if (i == 4)
		print4(a, (*a)->next->next->next, b);
	else if (i == 5)
		print5(a, (*a)->next->next->next->next, b);
	else
		return ;
}
