/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:41:04 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/06 19:16:17 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifdef MAXFD
#  undef MAXFD
#  define MAXFD 1024
# endif

# ifndef MAXFD
#  define MAXFD 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(const char *s);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);



#endif // GET_NEXT_LINE_H
