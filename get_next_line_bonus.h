/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:26:00 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/07 19:44:41 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUSH

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

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(char *s);
int		ft_big_strlen(t_list *lst);
void	ft_strcat(char **s1, char *s2, int end);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t n);
t_list	*ft_lstadd_back(t_list **lst, char *str);

#endif // GET_NEXT_LINE_BONUS_H
