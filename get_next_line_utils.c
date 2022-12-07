/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:43:10 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/07 14:55:14 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return (tmp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	i++;
	return (i);
}

int	ft_big_strlen(t_list *lst)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (lst)
	{
		i = 0;
		while (((char *)lst->content)[i])
		{
			if (((char *)lst->content)[i] == '\n')
				return (size + i);
			i++;
		}
		size += i;
		lst = lst->next;
	}
	return (size);
}

void	ft_strcat(char **s1, char *s2, int end)
{
	int	i;
	int	i2;

	i = 0;
	if (!s2)
		return ;
	if (!end)
		end = ft_strlen(s2);
	while (*s1)
		i2++;
	while (i < end)
	{
		(*s1)[i2] = (s2)[i];
		i++;
		i2++;
	}
}
