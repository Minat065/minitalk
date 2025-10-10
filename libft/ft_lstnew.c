/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:02:54 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 18:52:22 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

//新しいノードを作成する関数
//次のノードのアドレスを指してないのでコレはまだリストでは無いはず

// int	main(void)
//{
//	t_list	*list;
//	t_list	*list2;
//
//	list = ft_lstnew("Hello, world!");
//	printf("%s\n", (char *)list->content);
//	list2 = ft_lstnew("goodbye, world!");
//	list->next = list2;
//	printf("%s\n", (char *)list->next->content);
//	list2->next = list;
//	printf("%s\n", (char *)list->content);
//	printf("%s\n", (char *)list->next->content);
//	printf("%s\n", (char *)list->next->next->content);
//	return (0);
//}

// list1のnextにlist2のノードを繋げてあげるとリストになる。
