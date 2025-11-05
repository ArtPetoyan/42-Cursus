/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:56:56 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/26 13:08:21 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	uplow(unsigned int i, char c)
{
	char	a;

	if (i % 2 == 0)
		a = c - 32;
	else
		a = c;
	return (a);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*back;

	i = ft_strlen(s);
	back = (char *)malloc(i * sizeof(char) + 1);
	if (!back)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		back[i] = f(i, s[i]);
		i++;
	}
	back[i++] = '\0';
	return (back);
}
/*
int main()
{
	char a[] = "artur jan barev";
	char *str = ft_strmapi(a,&uplow);
	printf("%s", str);
	free(str);
}*/
