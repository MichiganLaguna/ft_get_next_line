/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:52:02 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/17 12:15:16 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Concatene the null-terminated string str1,
// at the end of the null-terminated string str.
void	ft_strcat(char *str, char *str1)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (!str || !str1)
		return (0);
	while (str[i])
		i++;
	while (str1[i2])
	{
		str[i + i2] = str1[i2];
		i2++;
	}
	str[i + i2] = 0;
}

int	ft_check_endl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_error(char *str, char *fd)
{
	if (str)
		free(str);
	if (fd)
		free(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*fd_lines[MAXFD];
	char		*buffer;
	int			bread;
	int			mbytes;
	int			fbytes;

	if (fd < 0 || fd > MAXFD)
		return (0);
	bread = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (buffer);
	fd_lines[fd] = malloc(sizeof(char) * 1);
	if (!fd_lines[fd])
		return (ft_error(buffer, fd_lines[fd]));
	fbytes = 0;
	mbytes = 1;
	while (bread && !(ft_check_endl(fd_lines[MAXFD])))
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == -1)
			return (ft_error(fd_lines, buffer));
		if (fbytes < bread)
		{
			mbytes *= 2;
			fbytes += mbytes / 2;
			fd_lines[fd] = ft_realloc(fd_lines[fd], mbytes);
		}
	}
}
