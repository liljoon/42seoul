/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:42:53 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/09 16:27:33 by isunwoo          ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	int		words_cnt;
	char	**res;
	
	words_cnt = count_words(s, c);
	res = malloc(sizeof(char*) * (words_cnt + 1));

}
