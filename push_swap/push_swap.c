/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:31:30 by apetoyan          #+#    #+#             */
/*   Updated: 2025/04/12 15:45:33 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_word(char **word)
{
	int			i;
	int			m;
	int			sign;

	i = -1;
	while (word[++i])
	{
		m = 0;
		sign = 1;
		if (word[i][m] == '+' || word[i][m] == '-')
		{
			if (word[i][m] == '-')
				sign = -1;
			m++;
		}
		if (!word[i][m])
			return (1);
		if (word[i])
		{
			if (my_f(word[i], sign))
				return (1);
		}
	}
	return (0);
}

static int	word_size(char **argv)
{
	int	i;
	int	j;
	int	back;

	i = 0;
	back = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] != '\0')
			{
				back++;
				while (argv[i][j] && argv[i][j] != ' ')
					j++;
			}
		}
		i++;
	}
	return (back - 1);
}

static int	main_helper1(t_s_str *vars, int argc, char *argv[])
{
	(*vars).i = 1;
	(*vars).l = 0;
	while ((*vars).i < argc)
	{
		(*vars).back = ft_split(argv[(*vars).i], ' ');
		if (!((*vars).back))
			return (1);
		if (!(*vars).back[0])
			return (free_sp((*vars).back), 1);
		if (check_word((*vars).back))
			return (free_sp((*vars).back), 1);
		(*vars).j = 0;
		while ((*vars).back[(*vars).j])
		{
			(*vars).my[(*vars).l] = ft_atoi((*vars).back[(*vars).j]);
			(*vars).index[(*vars).l] = (*vars).my[(*vars).l];
			((*vars).j)++;
			((*vars).l)++;
		}
		free_sp((*vars).back);
		((*vars).i)++;
	}
	if (insertion((*vars).index, (*vars).total))
		return (1);
	return (0);
}

static void	main_helper2(t_s_str *vars, t_m **a, t_m **node1)
{
	(*vars).i = 0;
	while ((*vars).i < (*vars).total)
	{
		(*vars).j = 0;
		while ((*vars).j < (*vars).total)
		{
			if ((*vars).my[(*vars).i] == (*vars).index[(*vars).j])
			{
				*node1 = ft_lstnew((*vars).my[(*vars).i], (*vars).j);
				ft_lstadd_back(a, *node1);
				break ;
			}
			((*vars).j)++;
		}
		((*vars).i)++;
	}
	free((*vars).index);
	free((*vars).my);
}

int	main(int argc, char **argv)
{
	t_m		*node1;
	t_m		*a;
	t_m		*b;
	t_s_str	vars;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	vars.total = word_size(argv);
	vars.index = malloc(sizeof(int) * vars.total);
	vars.my = malloc(sizeof(int) * vars.total);
	if (!(vars.index) || !(vars.my))
		return (free(vars.index), free(vars.my), write(2, "Error\n", 6));
	if (main_helper1(&vars, argc, argv))
		return (free(vars.index), free(vars.my), free_a(&a),
			write(2, "Error\n", 6));
	main_helper2(&vars, &a, &node1);
	if (sorted(a))
		return (free_a(&a), 0);
	main_all(&a, &b, &vars);
}
