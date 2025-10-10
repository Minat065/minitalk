/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:49:11 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/07 10:30:37 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*new;
// 	t_list	*new2;
// 	t_list	*new3;
// 	t_list	*head;

// 	head = NULL;
// 	new = ft_lstnew("new");
// 	new2 = ft_lstnew("new2");
// 	new3 = ft_lstnew("new3");
// 	ft_lstadd_front(&head, new);
// 	printf("part1\n");
// 	printf("head->content: %s\n", head->content);
// 	printf("head->next: %p\n", head->next);
// 	ft_lstadd_front(&head, new2);
// 	printf("part2\n");
// 	printf("head->content: %s\n", head->content);
// 	printf("head->next->content: %s\n", head->next->content);
// 	printf("head->next: %p\n", head->next);
// 	printf("head->next->next: %p\n", head->next->next);
// 	ft_lstadd_front(&head, new3);
// 	printf("part3\n");
// 	printf("head->content: %s\n", head->content);
// 	printf("head->next->content: %s\n", head->next->content);
// 	printf("head->next->next->content: %s\n", head->next->next->content);
// 	printf("head->next: %p\n", head->next);
// 	printf("head->next->next: %p\n", head->next->next);
// 	printf("head->next->next->next: %p\n", head->next->next->next);
// 	return (0);
// }
