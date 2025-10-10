/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:38:46 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:35:17 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*new;
// 	t_list	*new2;
// 	t_list	*new3;

// 	lst = NULL;
// 	new = ft_lstnew("new");
// 	ft_lstadd_back(&lst, new);
// 	printf("lst->content: %s\n", (char *)lst->content);
// 	printf("lst->next: %p\n", (void *)lst->next);
// 	new2 = ft_lstnew("new2");
// 	ft_lstadd_back(&lst, new2);
// 	printf("lst->content: %s\n", (char *)lst->content);
// 	printf("lst->next->content: %s\n", (char *)lst->next->content);
// 	printf("lst->next: %p\n", (void *)lst->next);
// 	printf("lst->next->next: %p\n", (void *)lst->next->next);
// 	new3 = ft_lstnew("new3");
// 	ft_lstadd_back(&lst, new3);
// 	printf("lst->content: %s\n", (char *)lst->content);
// 	printf("lst->next->content: %s\n", (char *)lst->next->content);
// 	printf("lst->next->next->content: %s\n", (char *)lst->next->next->content);
// 	printf("lst->next: %p\n", (void *)lst->next);
// 	printf("lst->next->next: %p\n", (void *)lst->next->next);
// 	printf("lst->next->next->next: %p\n", (void *)lst->next->next->next);
// 	return (0);
// }
