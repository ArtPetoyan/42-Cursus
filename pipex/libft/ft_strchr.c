/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:06:28 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/25 15:10:59 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*b;

	b = (char *) s;
	if (c % 256 == 0)
		return (b + ft_strlen(b));
	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == c % 256)
			return (b + i);
		i++;
	}
	return (NULL);
}
/*
int main() {
	int a = 'e' + 256;
	char str[] = "teste";
	printf("%d\n%c\n", a % 256, a);
	printf("%s\n", strchr(str, a));
	printf("%s", ft_strchr(str, a));
}
*/
