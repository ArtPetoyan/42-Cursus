/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:29:33 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/25 20:29:40 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	back = NULL;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	back = *lst;
	while (back->next)
		back = back->next;
	back->next = new;
}
/*
int main(void)
{
	t_list *node1 = ft_lstnew("Artur");
	t_list *node2 = ft_lstnew("jan");
	t_list *node3 = ft_lstnew("barev");

	node1->next = node2;
	t_list *all = node1;
	ft_lstadd_back(&all, node3);

	t_list *i = all;
	while (i)
	{
		printf("%s\n", (char *)i->content);
		i = i->next;
	}
}*/
