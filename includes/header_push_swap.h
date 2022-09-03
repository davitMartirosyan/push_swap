/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_push_swap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:20:43 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/02 20:52:34 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PUSH_SWAP_H
# define HEADER_PUSH_SWAP_H

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"

typedef struct s_stack
{
    int n;
    int idx;
    struct s_stack *next;
} Stack;


typedef struct s_actions
{
    void (*pa)(Stack **a, Stack **b);
    void (*pb)(Stack **a, Stack **b);
    void (*sa)(Stack **a, Stack *x);
    void (*sb)(Stack **b, Stack *x);
    void (*ss)(Stack **a, Stack *x, Stack **b, Stack *y);
    void (*ra)(Stack **a);
    void (*rb)(Stack **b);
    void (*rr)(Stack **a, Stack **b);
    void (*rra)(Stack **a);
    void (*rrb)(Stack **b);
    void (*rrr)(Stack **a, Stack **b);
} Actions;

typedef struct s_important
{
    int size;
    int length;
    int  *collection_of_ints;
    char *collection;
    char **split;
} t_important;


Actions init(void);

//parser functions
void stack_nums_counter(char **av, t_important *data);
void collect(char **av, t_important *data);
void store(Stack **a, t_important *data);

//Helpers
void __collecting_ints(t_important *data);
void __sorted__indacies(t_important *data);
void ___bubble___(int *arrtmp, int length);
void __store__(t_important *data);
int is_sorted(int *ints, int len);
int __repeats__(t_important *data);
int __check__collection(t_important *data);
int check_stack_length(Stack *stack);

void update_indacies(Stack **tmp);
void print_stack(Stack *stack);
//Error functions
int errno(char *errmsg);

//sorting algorithm functions
void a_b_sort(Stack **a, Stack **b, t_important *data, Actions action);
void pa(Stack **a, Stack **b);
void pb(Stack **a, Stack **b);
void sa(Stack **a, Stack *x);
void sb(Stack **b, Stack *x);
void ss(Stack **a, Stack *x, Stack **b, Stack *y);
void ra(Stack **a);
void rb(Stack **b);
void rr(Stack **a, Stack **b);
void rra(Stack **a);
void rrb(Stack **b);
void rrr(Stack **a, Stack **b);
void b_fly(Stack **a, Stack **b, t_important *data, Actions action);
void findhalf(Stack *tmp, Stack **b, int len);
int generate(int len);

//sorting parts
void tripple(Stack **a);
void quadruple(Stack **a, Stack **b, t_important *data);
void quintuple(Stack **a, Stack **b, t_important *data);
void centuple(Stack **a, Stack **b, t_important *data, Actions action);
#endif