/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:52:28 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/17 14:57:44 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the length of str.
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

// Returns an exact malloc'ed copy of up to ln characters from str.
char	*ft_strdup(char *str, int ln)
{
	int		i;
	char	*out;

	if (!str)
		return (0);
	i = 0;
	out = malloc(sizeof(char) * (ln + 1));
	if (!out)
		return (out);
	while (str[i] && i < ln)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

// Cut str in two, returning the first part as a new malloc'ed string
// and leaving the rest in str.
char	*ft_strncut(char **str, int ln)
{
	int		i;
	int		len;
	char	*out;
	char	*tmp;

	if (!str || !(*str))
		return (0);
	i = 0;
	len = ft_strlen(*str);
	if (ln > len)
		ln = len;
	out = ft_strdup(*str, ln);
	if (!out)
		return (out);
	tmp = ft_strdup((*str) + ln, len - ln);
	if (!tmp)
	{
		free(out);
		return (tmp);
	}
	free((*str));
	*str = tmp;
	return (out);
}

// Re-Allocate the previously allocated string in str,
// making the new string size bytes long,
// freeing str and returning the newly created string
void	*ft_realloc(char **str, size_t size)
{
	char	*out;
	int		ln;

	if (!str)
		return (0);
	ln = ft_strlen(*str);
	if (ln > size)
		return (0);
	out = malloc(sizeof(char) * (size + 1));
	if (!out)
		return (out);
	out[0] = 0;
	ft_strcat(out, *str);
	free((*str));
	return (out);
}
