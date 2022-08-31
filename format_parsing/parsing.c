/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:16:21 by dmartiro          #+#    #+#             */
/*   Updated: 2022/08/28 16:08:17 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void stack_nums_counter(char **av, t_important *data)
{
    int i;
    int charcount;

    i = 0;
    charcount = 0;
    while(av[++i])
        charcount += ft_strlen(av[i]);
    data->size = charcount;
}

static int check_char(char c, t_important *data)
{
    if((c < '0' || c > '9') && 
        c != ' ' && c != '-')
    {
        data->collection = NULL;       
        return (0);
    }
    return (1);
}

void collect(char **av, t_important *data)
{
    int i;
    int c;
    int j;
    char *str;

    i = 0;
    j = -1;
    str = malloc(sizeof(char) * ((data->size * 2) + 1));
    if (!str)
        return ;
    while (av[++i])
    {
        c = -1;
        while (av[i][++c])
        {
            if (!check_char(av[i][c], data))
            {
                free(str);
                return ;
            }
            str[++j] = av[i][c];
        }
        str[++j] = ' ';
    }
    str[j] = '\0';
    data->collection = str;
}

void store(Stack **a, t_important *data)
{
    int i;
    
    while(*a) a = &((*a)->next);
    i = 0;
    while(i < data->length)
    {
       *a = malloc(sizeof **a);
       (*a)->n = data->collection_of_ints[i];
       a = &((*a)->next);
       i++;
    }
}

int check_stack_length(Stack *stack)
{
    Stack *t;
    int i;

    t = stack;
    i = -1;
    while(t != NULL)
    {
        t = t->next;
        ++i;
    }
    return (i);
}