/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:00:04 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/25 20:12:06 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*back;
	size_t	m;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	m = ft_strlen(s);
	while (s[i] != '\0' && i < len && i < m - start)
		i++;
	if (start >= m)
		return ((char *) ft_calloc(1, sizeof(char)));
	back = (char *)malloc(i * sizeof(char) + 1);
	if (!back)
		return (NULL);
	i = 0;
	while (i < len && i < m - start)
	{
		back[i] = s[start + i];
		i++;
	}
	back[i] = '\0';
	return (back);
}
/*
int	main()
{
	const char *a = ft_substr("hola", 2, 30);
	printf("%s",a);
}
*/
