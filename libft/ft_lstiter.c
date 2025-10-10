/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:04:55 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 20:12:08 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	function(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst2;
// 	t_list	*lst3;

// 	lst = ft_lstnew(strdup("Hello, World!"));
// 	lst2 = ft_lstnew(strdup("Hello, World!1"));
// 	lst3 = ft_lstnew(strdup("Hello, World!2"));
// 	lst->next = lst2;
// 	lst2->next = lst3;
// 	ft_lstiter(lst, function);
// 	return (0);
// }
