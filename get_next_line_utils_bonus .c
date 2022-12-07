/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus .c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:43:10 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/07 19:41:57 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*ptr;
	size_t	i;
	size_t	c;

	c = nmemb * n;
	if (!c)
		return (malloc(0));
	if (c / n != nmemb)
		return (0);
	ptr = malloc(c);
	i = 0;
	if (ptr)
	{
		while (i < c)
		{
			((unsigned char *)ptr)[i] = 0;
			i++;
		}
	}
	return (ptr);
}

t_list	*ft_lstadd_back(t_list **lst, char *content)
{
	t_list	*new;
	int		i;

	new = ft_calloc(1, sizeof(t_list));
	new->next = 0;
	new->content = ft_calloc(1, ft_strlen(content) + 1);
	i = 0;
	while (content[i])
	{
		(new->content)[i] = content[i];
		i++;
	}
	if (*lst)
	{
		while ((*lst)->next)
			lst = &(*lst)->next;
		(*lst)->next = new;
	}
	else
		(*lst) = new;
	return (new);
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
				return (size + i + 1);
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
	i2 = 0;
	if (!s2)
		return ;
	if (end == -1)
		end = ft_strlen(s2);
	while ((*s1)[i2])
		i2++;
	while (i <= end)
	{
		(*s1)[i2] = (s2)[i];
		i++;
		i2++;
	}
}
