/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:30:45 by apetoyan          #+#    #+#             */
/*   Updated: 2025/01/25 20:31:54 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	while (*lst)
	{
		new = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = new;
	}
}
/*
void	del(voic *c)
{
	free(c);
}
int main() {
    t_list *node1 = ft_lstnew(ft_strdup("Artur"));
    t_list *node2 = ft_lstnew(ft_strdup("jan"));
    t_list *node3 = ft_lstnew(ft_strdup("!"));

    node1->next = node2;
	node2->next = node3;

    t_list *current = node1;
	while(current)
	{
		printf("%s\n",(char *)current->content);
		current = current->next;
	}
    ft_lstclear(&node1,&del);
	if(!node1)
		printf("ha jan");
}
*/
