/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 08:36:11 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/27 08:37:10 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifdef MAXFD
#  undef MAXFD
# endif

# define MAXFD 1024

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *str, int ln);
char	*ft_strncut(char **str, int ln);
void	*ft_realloc(char **str, size_t size);
void	ft_strcat(char *str, char *str1);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_BONUS_H