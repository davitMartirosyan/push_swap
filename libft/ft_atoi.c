/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:22:50 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/07 22:15:18 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	counter;
	long int	syb;

	i = 0;
	counter = 0;
	syb = 1;
	if (nptr == (void *)0)
		return (0);
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\r'
		|| nptr[i] == '\v'
		|| nptr[i] == '\f'
		|| nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		syb = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		counter = counter * 10 + nptr[i++] - '0';
	return (syb * counter);
}
