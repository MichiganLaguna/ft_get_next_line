/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:12 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/07 13:08:22 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	while (i++ < 5)
		printf("%d:", i);
	i = -1;
	printf("\n");
	while (++i < 5)
		printf("%d:", i);
	return (0);
}