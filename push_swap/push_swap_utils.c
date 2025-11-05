/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:31:36 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/12 16:53:55 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_a(t_m **a)
{
	t_m	*tmp;

	tmp = NULL;
	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

int	my_f(char *a, int sign)
{
	ssize_t	num;
	int		i;

	i = -1;
	num = 0;
	if (a[0] == '+' || a[0] == '-')
		i++;
	while (a[++i] != '\0')
		if (!ft_isdigit(a[i]))
			return (1);
	num = ft_atoi(a);
	if ((sign < 0 && num > 0) || (sign > 0 && num < 0))
		return (1);
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

void	main_all(t_m **a, t_m **b, t_s_str *vars)
{
	if ((*vars).total < 6)
		my_p(a, b, (*vars).total);
	else
	{
		command(&(*a), &(*b), my_n((*vars).total));
		push_b(&(*a), &(*b), my_n((*vars).total));
	}
	free_a(a);
}

void	free_sp(char **back)
{
	int	i;

	i = 0;
	while (back[i])
	{
		free(back[i]);
		i++;
	}
	free(back);
}
