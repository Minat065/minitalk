/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:13:22 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/07 11:59:40 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void del(void *content)
// {
// 	free(content);
// }

// void *f(void *content)
// {
// 	return (content);
// }

// int main()
// {
// 	t_list *lst = ft_lstnew(ft_strdup("hello"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("42")));
// 	t_list *new_lst = ft_lstmap(lst, f, del);
// 	while (new_lst)
// 	{
// 		printf("%s\n", (char *)new_lst->content);
// 		new_lst = new_lst->next;
// 	}
// }
