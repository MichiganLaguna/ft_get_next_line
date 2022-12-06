/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:14:46 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/06 19:32:48 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*fd_list[MAXFD];
	char			*buffer;
	int				cread;

	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buffer)
		return (buffer);
	cread = read(fd, buffer, BUFFER_SIZE);
	if (!cread || cread == -1)
		return (free(buffer), ft_lstclear (char *)0);
	ft_lstaddback();
}
