/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:16:31 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 20:03:52 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *lst;
// 	t_list *lst2;
// 	t_list *lst3;

// 	lst = ft_lstnew(strdup("Hello, World!"));
// 	lst2 = ft_lstnew(strdup("Hello, World!1"));
// 	lst3 = ft_lstnew(strdup("Hello, World!2"));

// 	lst->next = lst2;
// 	lst2->next = lst3;

// 	while (lst)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}

// 	ft_lstclear(&lst, del);

// 	printf("After clear\n");
// 	printf("lst: %s\n", (char *)lst);
// 	printf("lst2: %s\n", (char *)lst2);
// 	printf("lst3: %s\n", (char *)lst3);

// 	return (0);
// }