/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:55:00 by apetoyan          #+#    #+#             */
/*   Updated: 2025/02/16 18:32:57 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_sep(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_extract(char **str, int s, int add_nl)
{
	char	*back;
	int		i;

	back = (char *)malloc(s + add_nl + 1);
	if (!back)
		return (NULL);
	i = 0;
	while (i < s && (*str)[i])
	{
		back[i] = (*str)[i];
		i++;
	}
	if (add_nl)
		back[i++] = '\n';
	back[i] = '\0';
	return (back);
}

char	*ft_fill(char **str)
{
	char	*back;
	char	*rem;
	int		s;
	int		add_nl;

	s = 0;
	while ((*str)[s] && (*str)[s] != '\n')
		s++;
	add_nl = ((*str)[s] == '\n');
	back = ft_extract(str, s, add_nl);
	if (!back)
		return (free(*str), *str = NULL, NULL);
	if ((*str)[s])
		rem = ft_merge(NULL, *str + s + add_nl);
	else
		rem = NULL;
	free(*str);
	*str = rem;
	return (back);
}
