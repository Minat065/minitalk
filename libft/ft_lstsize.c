/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:40:12 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:36:29 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*current;

	length = 0;
	current = lst;
	while (current)
	{
		length++;
		current = current->next;
	}
	return (length);
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 	t_list	*lst4;

// 	lst = ft_lstnew("1");
// 	lst2 = ft_lstnew("2");
// 	lst3 = ft_lstnew("3");
// 	lst4 = ft_lstnew("4");
// 	lst->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = lst4;
// 	printf("%d\n", ft_lstsize(lst));
// 	return (0);
// }
