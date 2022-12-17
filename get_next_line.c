/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:52:02 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/17 15:05:04 by nriviere         ###   ########.fr       */
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
	int			bread;
	int			mbytes;
	int			fbytes;
	int			end;

	if (fd < 0 || fd > MAXFD)
		return (0);
	bread = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (buffer);
	fbytes = 0;
	mbytes = 1;
	end = (ft_check_endl(fd_lines[fd]));
	while (bread && end == -1)
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == -1)
			return (free(fd_lines[fd]), free(buffer), (char *)0);
		if (bread == 0)
			return (free(buffer), ft_strncut(&(fd_lines[fd]),
					ft_check_endl(fd_lines[fd]) + 1));
		if (fbytes < bread)
		{
			while (fbytes < bread)
			{
				mbytes *= 2;
				fbytes += mbytes / 2;
			}
			fd_lines[fd] = ft_realloc(&fd_lines[fd], mbytes);
		}
		ft_strcat(fd_lines[fd], buffer);
		end = ft_check_endl(fd_lines[fd]);
		fbytes -= bread;
	}
	printf("$%s$", fd_lines[fd]);
	free(buffer);
	return (ft_strncut(&(fd_lines[fd]), ft_check_endl(fd_lines[fd]) + 1));
}

int	main(void)
{
	int		fd;
	char	*out;
	char	*str;

	fd = open("15.yxt", O_RDONLY);
	out = get_next_line(fd);
	printf(":%s:", out);
	free(out);
	out = get_next_line(fd);
	printf(":%s:", out);
	free(out);
	out = get_next_line(fd);
	printf(":%s:", out);
	free(out);
	out = get_next_line(fd);
	printf(":%s:", out);
	free(out);
	// out = get_next_line(fd);
	// free(out);
	// out = malloc(10);
	// out[0] = 0;
	// printf(":%s:", out);
	// str = ft_strdup("Hello", 5);
	// printf(":%s:", str);
	// ft_strcat(out, str);
	// printf(":%s:", out);

	return (0);
}
