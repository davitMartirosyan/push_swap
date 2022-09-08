/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:16:21 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/08 20:38:33 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	stack_nums_counter(char **av, t_import *data)
{
	int	i;
	int	charcount;

	i = 0;
	charcount = 0;
	while (av[++i])
		charcount += ft_strlen(av[i]);
	data->size = charcount;
}

static int	check_char(char c, char d)
{	
	if ((c < '0' || c > '9')
		&& c != ' ' && c != '-' && c != '+')
		return (0);
	else if (d == '-' || d == '+')
		return (0);
	else if ((c == '-' || c == '+') && (d < '0' || d > '9'))
		return (0);
	return (1);
}

void	collect(char **av, t_import *data)
{
	int		i;
	int		c;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	str = malloc(sizeof(char) * ((data->size * 2) + 1));
	while (av[++i])
	{
		c = -1;
		while (av[i][++c])
		{
			if (!check_char(av[i][c], av[i][c + 1]))
			{
				data->collection = NULL;
				return ;
			}
			str[++j] = av[i][c];
		}
		str[++j] = ' ';
	}
	str[j] = '\0';
	data->collection = str;
}

void	store(t_stack **a, t_import *data)
{
	int	i;

	while (*a)
		a = &((*a)->next);
	i = -1;
	while (++i < data->length)
	{
		*a = malloc(sizeof **a);
		(*a)->n = data->collection_of_ints[i];
		(*a)->idx = i;
		a = &((*a)->next);
	}
	(*a) = NULL;
}

int	check_stack_length(t_stack *stack)
{
	t_stack	*t;
	int		i;

	t = stack;
	i = -1;
	while (t != NULL)
	{
		t = t->next;
		++i;
	}
	return (i);
}
