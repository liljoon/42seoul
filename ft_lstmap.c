/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:06:11 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/11 19:16:28 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*it;
	t_list	*res;
	t_list	*temp;

	it = lst;
	while (!it)
	{
		temp = ft_lstnew(f(it->content));
		if	(!temp)
		{
			ft_lstclear(res);
			return (NULL);
		}
		ft_lstadd_back(res, temp);
		it = it->next;
	}
	return (res);
}