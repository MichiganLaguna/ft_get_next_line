/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:52:02 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/19 17:35:47 by nriviere         ###   ########.fr       */
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
		return ;
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
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*fd_lines[MAXFD];
	char		*buffer;
	char		*out;
	int			i[4];

	if (fd < 0 || fd > MAXFD)
		return (0);
	i[4] = ft_check_endl(fd_lines[fd]);
	if (i[4] != -1)
		return (ft_strncut(&(fd_lines[fd]), i[4] + 1));
	i[0] = 1;
	i[1] = 0;
	i[2] = 1;
	fd_lines[fd] = malloc(1);
	fd_lines[fd][0] = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(out), buffer);
	while (i[0] > 0 && i[4] != -1)
	{
		i[0] = read(fd, buffer, BUFFER_SIZE);
		buffer[i[0]] = 0;
		if (i[0] < i[1])
		{
			i[2] *= 2;
			i[1] += i[2] / 2;
			fd_lines[fd] = ft_realloc(&(fd_lines[fd]),i[2]);
		}
		ft_strcat(fd_lines[fd], buffer);
	}
	return (0);
}

int	main(void)
{
	int		fd;
	char	*out;
	char	*str;

	fd = open("15.yxt", O_RDONLY);
	out = get_next_line(fd);
	printf(":%s:", out);
	return (0);
}
