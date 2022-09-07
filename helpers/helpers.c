/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:35:43 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/07 22:12:50 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	__collecting_ints(t_import *data)
{
	__store__(data);
	__sorted__indacies(data);
}

void	__store__(t_import *data)
{
	int	i;

	i = 0;
	data->split = ft_split(data->collection, ' ');
	while (data->split[i])
		i++;
	data->length = i;
	data->collection_of_ints = malloc(sizeof(int) * (i));
	i = -1;
	while (data->split[++i])
	{
		if (ft_atoi(data->split[i]) < INT_MIN
			|| ft_atoi(data->split[i]) > INT_MAX)
			errno("[Collection Error] : MIN_MAX Error");
		// if(!ft_atoi(data->split[i]))
		// 	errno("[Collection Error] : NaN");
		data->collection_of_ints[i] = ft_atoi(data->split[i]);
	}
	
}

void	__sorted__indacies(t_import *data)
{
	int	*sorted;
	int	i;
	int	c;

	i = -1;
	sorted = malloc(sizeof(int) * data->length);
	while (++i < data->length)
		sorted[i] = data->collection_of_ints[i];
	___bubble___(sorted, data->length);
	i = -1;
	while (++i < data->length)
	{
		c = -1;
		while (++c < data->length)
		{
			if (sorted[i] == data->collection_of_ints[c])
			{
				data->collection_of_ints[c] = i;
				break ;
			}
		}
	}
}

int	__repeats__(t_import *data)
{
	int	i;
	int	c;

	i = -1;
	__store__(data);
	while (++i < data->length)
	{
		c = i;
		while (++c < data->length)
			if (data->collection_of_ints[i] == data->collection_of_ints[c])
				return (1);
	}
	return (0);
}

int	__check__collection(t_import *data)
{
	if (!data->collection)
		errno("[Collection Error] : NaN");
	if (__repeats__(data))
		errno("[Collection Error] : Same Num");
	if (is_sorted(data->collection_of_ints, data->length))
		ft_printf("is sorted\n");
	return (1);
}
