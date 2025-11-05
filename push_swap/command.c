/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:33:03 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/12 16:51:21 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_m *stack)
{
	while (stack->next)
	{
		if (stack->num < stack->next->num)
			stack = stack ->next;
		else
			return (0);
	}
	return (1);
}

int	my_n(int size)
{
	if (size >= 10 && size < 50)
		return (3);
	else if (size >= 50 && size < 100)
		return (8);
	else if (size >= 100 && size < 250)
		return (15);
	else if (size >= 250 && size < 350)
		return (22);
	else if (size >= 350 && size < 500)
		return (26);
	else if (size >= 500)
		return (30);
	else
		return (1);
}

void	command(t_m **a, t_m **b, int i)
{
	int	ctr;

	ctr = 0;
	while (*a)
	{
		if ((*a)->index <= ctr)
		{
			pb(b, a);
			rb(b);
			ctr++;
		}
		else if ((*a)->index <= ctr + i)
		{
			pb(b, a);
			ctr++;
		}
		else
			ra(a);
	}
}

static int	index_find(t_m *lst, int n)
{
	int	back1;
	int	back2;
	int	j;

	j = -1;
	back1 = lst->index;
	while (j++ < n && lst->next)
	{
		if (back1 < lst->next->index)
			back1 = lst->next->index;
		lst = lst->next;
	}
	j = -1;
	ft_lstlast(&lst);
	back2 = lst->index;
	while (++j < n && lst->prev)
	{
		if (back2 < lst->prev->index)
			back2 = lst->prev->index;
		lst = lst->prev;
	}
	if (back1 > back2)
		return (back1);
	return (-back2);
}

void	push_b(t_m **a, t_m **b, int n)
{
	int	o;

	while (*b)
	{
		o = index_find(*b, n);
		if ((*b)->next)
		{
			if (o > 0)
				while ((*b)->index != o)
					rb(b);
			else
				while ((*b)->index != -o)
					rrb(b);
		}
		pa(a, b);
	}
}
