/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:42:53 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/11 15:42:19 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_words(char const *s, char c)
{
	int	flag;
	int	idx;
	int res;
	
	res = 0;
	idx = 0;
	flag = 0;
	while (s[idx])
	{
		if (s[idx] != c && !flag)
		{
			res++;
			flag = 1;
		}
		else if (s[idx] == c && flag)
			flag = 0;
		idx++;
	}
	return (res);
}

static int	str_len(char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx] != c && str[idx] != '\0')
		idx++;
	return (idx);
}

char	**ft_split(char const *s, char c)
{
	int		words_cnt;
	char	**res;
	int		words_idx;
	int		str_idx;

	words_idx = 0;
	str_idx = 0;
	
	words_cnt = count_words(s, c);
	res = malloc(sizeof(char*) * (words_cnt + 1));
	if (!res)
		return (res);
	while (words_idx < words_cnt)
	{				
		while (s[str_idx] != c)
			str_idx++;
		res[words_idx] = malloc(sizeof(char) * (str_len(s + str_idx, c) + 1));
		ft_memcpy(res[words_idx], s + str_idx, str_len(s + str_idx, c));
		res[words_idx][str_len(s + str_idx, c) - 1] = '\0';
		words_idx++;
	}
	res[words_idx] = 0;
	return (res);
}
