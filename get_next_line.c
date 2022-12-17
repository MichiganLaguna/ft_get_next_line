/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:52:02 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/17 17:38:33 by nriviere         ###   ########.fr       */
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
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (buffer);
	i[0] = ft_check_endl(fd_lines[fd]);
	i[1] = 1;
	i[2] = 0;
	i[3] = 1;
	while (i[3] && i[0] == -1)
	{
		i[3] = read(fd, buffer, BUFFER_SIZE);
		if (i[3] == -1)
			return (free(buffer), free(fd_lines[fd]), (char *)0);
		if (i[3] == 0)
			return (free(buffer), ft_strncut(&(fd_lines[fd]),
					ft_check_endl(fd_lines[fd]) + 1));
		if (i[2] < i[3])
		{
			while (i[2] < i[3])
			{
				i[1] *= 2;
				i[2] += i[1] / 2;
			}
			fd_lines[fd] = ft_realloc(&(fd_lines[fd]), i[1]);
		}
		ft_strcat(fd_lines[fd], buffer);
		i[0] = ft_check_endl(fd_lines[fd]);
		i[2] -= i[3];
	}
	free(buffer);
	return (ft_strncut(&(*fd_lines),
			ft_check_endl(*fd_lines)));
}

int	main(void)
{
	int		fd;
	char	*out;
	char	*str;

	fd = open("15.yxt", O_RDONLY);
	out = get_next_line(fd);
	printf(":%s:", out);
	// free(out);
	
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
