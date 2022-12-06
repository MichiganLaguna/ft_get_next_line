/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:43:10 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/06 19:32:43 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*ptr;
	size_t	c;

	c = nmemb * n;
	if (!c)
		return (malloc(0));
	if (c / n != nmemb)
		return (0);
	ptr = malloc(c);
	if (ptr)
		while (c--)
			((unsigned char *)ptr)[c] = 0;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = (unsigned int)ft_strlen(s);
	if (len_s < start)
		len = 0;
	if (len > len_s - start)
		len = len_s - start;
	i = 0;
	out = ft_calloc(len + 1, sizeof(char));
	if (out)
	{
		while (i < len && s[start + i])
		{
			out[i] = s[start + i];
			i++;
		}
	}
	return (out);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	out = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (*s1)
	{
		out[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		out[i] = *s2;
		i++;
		s2++;
	}
	return (out);
}

t_list	*ft_lstadd_back(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (0);
	new = malloc(1 * sizeof(t_list));
	if (!new)
		return (new);
	new->content = content;
	new->next = 0;
	tmp = *lst;
	while (tmp)
		tmp = tmp->next;
	tmp = new;
}
