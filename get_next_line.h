/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:41:04 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/07 14:40:48 by nriviere         ###   ########.fr       */
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
# endif

# define MAXFD 1024

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(char *s);
int		ft_big_strlen(t_list *lst);
void	ft_strcat(char **s1, char *s2, int end);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
t_list	*ft_lstadd_back(t_list **lst, void *content);

#endif // GET_NEXT_LINE_H
