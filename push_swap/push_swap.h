/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:31:42 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/12 16:46:51 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	free_sp(char **back);
void	free_a(t_m **a);
int		my_f(char *a, int sign);
void	main_all(t_m **a, t_m **b, t_s_str *vars);
void	push_b(t_m **a, t_m **b, int n);
void	command(t_m **a, t_m **b, int i);
int		my_n(int size);
void	my_p(t_m **a, t_m **b, int i);
int		sorted(t_m *stack);
int		insertion(int *i, int m);
void	pa(t_m **b, t_m **a);
void	pb(t_m **b, t_m **a);
void	sa(t_m **stack);
void	sb(t_m **stack);
void	ss(t_m **stack1, t_m **stack2);
void	ra(t_m **stack);
void	rb(t_m **stack);
void	rr(t_m **stack);
void	rra(t_m **stack);
void	rrb(t_m **stack);
void	rrr(t_m **stack);

#endif
