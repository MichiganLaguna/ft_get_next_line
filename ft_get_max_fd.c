/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:44:22 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/06 18:30:36 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

void	main(void)
{
	int	t;

	while (1)
	{
		t = open("test", O_RDONLY);
		if (t < 0)
		{
			perror("open");
			break ;
		}
	}
	printf("%d: ok\n", t);
}
