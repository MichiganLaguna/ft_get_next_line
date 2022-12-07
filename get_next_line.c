/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:14:46 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/07 15:07:14 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findendl(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (0);
}

char	*ft_big_join(t_list **lst)
{
	t_list	*tmp;
	char	*out;
	int		endl;

	out = ft_calloc(1, ft_big_strlen(*lst) + 1);
	if (!out)
		return (out);
	while (*lst)
	{
		endl = ft_findendl((*lst)->content);
		tmp = (*lst)->next;
		ft_strcat(&out, (*lst)->content, endl);
		if (endl)
			break ;
		free((*lst)->content);
		free(*lst);
		(*lst) = tmp;
	}
	return (out);
}

void	ft_lstfree(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*fd_list[MAXFD];
	char			*buffer;
	char			*out;
	int				cread;

	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buffer)
		return (buffer);
	while (!ft_findendl(buffer))
	{
		cread = read(fd, buffer, BUFFER_SIZE);
		if (cread == -1)
			return (ft_lstfree(&fd_list[fd]), free(buffer), (char *)0);
		if (cread == 0)
			break ;
		ft_lstadd_back(&fd_list[fd], buffer);
	}
	out = ft_big_join(&fd_list[fd]);
	free(buffer);
	ft_lstfree(&fd_list[fd]);
	return (out);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	printf(":%s:", get_next_line(fd));
	return (0);
}
