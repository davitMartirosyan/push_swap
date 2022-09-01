#include "../includes/header_push_swap.h"

void tripple(Stack **a)
{
    int n[3];

    n[0] = (*a)->n;
    n[1] = (*a)->next->n;
    n[2] = (*a)->next->next->n;
    if(n[0] == 1 && n[1] == 0)
        sa(a, (*a)->next);
    else if(n[0] == 1 && n[1] == 2)
        rra(a);
    else if(n[0] == 2 && n[1] == 0)
        ra(a);
    else if(n[0] == 2 && n[1] == 1)
    {
        sa(a, (*a)->next);
        rra(a);
    }
    ft_printf("%d\n", (*a)->n);
}

void quadruple(Stack **a, Stack **b)
{
    ft_printf("4\n");
}

void quintuple(Stack **a, Stack **b)
{
    ft_printf("5\n");
}

void centuple(Stack **a, Stack **b, t_important *data, Actions action)
{
    int mx;
    int len;
    Stack *tmp;
    
    b_fly(a, b, data, action);
    tmp = *b;
    mx = data->length - 1;
    len = data->length;
    while (tmp)
    {
        if (tmp->n == mx)
        {
            findhalf(tmp, b, mx, len);
            action.pa(a, b);
            tmp = *b;
            mx--;
            len--;
            update_indacies(b);
        }
        else
            tmp = tmp->next;
    }  
}