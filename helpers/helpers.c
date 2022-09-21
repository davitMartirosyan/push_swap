/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:35:43 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/21 11:09:57 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	collecting_ints(t_import *data)
{
	__store__(data);
	__sorted__indacies(data);
}

void	__store__(t_import *data)
{
	int	i;
	int	a;

	a = -1;
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
			errno();
		data->collection_of_ints[i] = ft_atoi(data->split[i]);
	}
	while (data->split[++a])
		free(data->split[a]);
	free(data->split);
}

void	__sorted__indacies(t_import *data)
{
	long int	*sorted;
	int			i;
	int			c;

	i = -1;
	sorted = malloc(sizeof(long int) * data->length);
	while (++i < data->length)
		sorted[i] = data->collection_of_ints[i];
	___bubble___(sorted, data->length);
	i = -1;
	while (++i < data->length)
	{
		c = -1;
		while (++c < data->length)
		{
			if (sorted[c] == data->collection_of_ints[i])
			{
				data->collection_of_ints[i] = c;
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
	free(data->collection_of_ints);
	return (0);
}

int	__check__collection(t_import *data)
{
	if (!data->collection)
		return (0);
	if (__repeats__(data))
		return (0);
	return (1);
}
