/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:14:46 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/07 19:41:12 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_findendl(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

void	ft_cutstart(char **str)
{
	char	*tmp;
	int		new_size;
	int		i;
	int		i2;

	i = ft_findendl(*str);
	if (i < 0)
		i = 0;
	i2 = 0;
	new_size = ft_strlen(*str) - i;
	tmp = ft_calloc(1, new_size);
	if (!tmp)
		return ;
	while ((*str)[i++])
		tmp[i2++] = (*str)[i];
	free(*str);
	*str = tmp;
	return ;
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
		if (endl > -1)
		{
			ft_cutstart(&(*lst)->content);
			if (!(*lst)->content)
				return ((char *)0);
			break ;
		}
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
	while (ft_findendl(buffer) == -1)
	{
		cread = read(fd, buffer, BUFFER_SIZE);
		if (cread == -1)
			return (ft_lstfree(&fd_list[fd]), free(buffer), (char *)0);
		if (cread == 0)
			break ;
		buffer[cread] = 0;
		if (!ft_lstadd_back(&fd_list[fd], buffer))
			return (ft_lstfree(&fd_list[fd]), free(buffer), (char *)0);
	}
	out = ft_big_join(&fd_list[fd]);
	free(buffer);
	return (out);
}
