/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:55:10 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/19 20:20:41 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	my_f(unsigned int i,char *str)
{
		printf("%c",str);
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f (i, &s[i]);
		i++;
	}
}
/*
int main()
{
	char a[] = "Artur jan barev";
   ft_striteri(a, &my_f);
}*/
