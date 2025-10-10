/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:53:41 by mirokugo          #+#    #+#             */
/*   Updated: 2024/06/16 16:06:16 by mirokugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words_comb(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*ft_split_process(char const *s, char c, int *i, int *wordlength)
{
	char	*result;

	*wordlength = 0;
	while (s[*i + *wordlength] && s[*i + *wordlength] != c)
		(*wordlength)++;
	result = ft_substr(s, *i, *wordlength);
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_free_split(char **result, int j)
{
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
	return (NULL);
}

char	**ft_mem_allocate(char const *s, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count_words_comb(s, c) + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		wordlength;

	result = ft_mem_allocate(s, c);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			result[j] = ft_split_process(s, c, &i, &wordlength);
			if (!result[j])
				return (ft_free_split(result, j));
			j++;
			i += wordlength;
		}
	}
	result[j] = NULL;
	return (result);
}

// int main(void)
// {
// 	char *str = "1234a12aa12321";
// 	char set = '1';

// 	char **result = ft_split(str, set);
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }
