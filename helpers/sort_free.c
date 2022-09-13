/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:38:39 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/11 04:41:54 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	___bubble___(long int *arrtmp, int length)
{
	int	i;
	int	c;
	int	tmp;

	i = -1;
	while (++i < length)
	{
		c = 0;
		while (c < length)
		{
			if (arrtmp[i] < arrtmp[c])
			{
				tmp = arrtmp[i];
				arrtmp[i] = arrtmp[c];
				arrtmp[c] = tmp;
			}
			c++;
		}
	}
}
