/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:11:43 by mirokugo          #+#    #+#             */
/*   Updated: 2024/05/03 17:36:00 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		if (current->next == NULL)
			return (current);
		current = current->next;
	}
	return (NULL);
}

// int	main(void)
// {
// 	t_list *lst = ft_lstnew("first");
// 	t_list *last;

// 	ft_lstadd_front(&lst, ft_lstnew("second"));
// 	ft_lstadd_front(&lst, ft_lstnew("third"));
// 	ft_lstadd_front(&lst, ft_lstnew("fourth"));
// 	last = ft_lstlast(lst);
// 	printf("%s\n", (char *)last->content);
// 	return (0);
// }