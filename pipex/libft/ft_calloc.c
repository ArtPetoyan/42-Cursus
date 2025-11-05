/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:38:27 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/25 23:15:00 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	c;

	c = count * size;
	ptr = (void *) malloc(c);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, c);
	return (ptr);
}
/*
int main() {
	char str[] = "Artur";
	int i = 0;

	char *str1 = (char *) calloc(6, 1);
	char *str2 = (char *) ft_calloc(sizeof(str) + 1, sizeof(str[0]));
	
	while(str[i] != '\0')
	{
		str1[i] = str[i];
		str2[i] = str[i];
		i++;
	}
	printf("%s\n", str1);
	printf("%s", str2);
	
	free(str1);
	free(str2);	
}
*/
