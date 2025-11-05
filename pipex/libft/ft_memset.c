/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:34:03 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/18 15:09:32 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
/*
int main()
{
	char str[] = "Artur barev dzez";
	char str1[] = "Artur barev dzez";
	memset(str, 'O', 5);
	printf("%s\n", str);
	ft_memset(str1, 'O', 5);
	printf("%s", str1);
}
*/
