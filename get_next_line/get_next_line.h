/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:32:13 by isunwoo           #+#    #+#             */
/*   Updated: 2022/07/26 19:58:35 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	content[BUFFER_SIZE];
	int		pos;
	int		read_len;
}	t_buffer;

char	*get_next_line(int fd);
int		get_length(t_buffer *buff);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*str_push_back(char *origin, char *content, int length);
size_t	ft_strlen(const char *s);

#endif
