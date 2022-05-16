/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:28:50 by skhali            #+#    #+#             */
/*   Updated: 2022/05/16 06:08:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_stack **s_a)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    first = *s_a;
    second = (*s_a)->next;
    third = (*s_a)->next->next;

    if((first-> value > second->value) && (second->value < third->value) 
        && (first->value < third->value))
        swap_a(s_a);
    else if ((first-> value > second->value) && (second->value > third->value) 
        && (first->value > third->value))
    {
        swap_a(s_a);
        rrotate_a(s_a);
    }
    else if((first-> value > second->value) && (second->value < third->value) 
        && (first->value > third->value))
        rotate_a(s_a);
    else if((first-> value < second->value) && (second->value > third->value) 
        && (first->value < third->value))
    {
        swap_a(s_a);
        rotate_a(s_a);
    }
    else
        rrotate_a(s_a);
}

void	four_sort(t_stack **s_a, t_stack **s_b)
{
    push_b(s_b, s_a);
    three_sort(s_a);
    move_el_to_a(s_a, s_b);;
    slidetosort(s_a);
}

void	five_sort(t_stack **s_a, t_stack **s_b)
{
    push_b(s_b, s_a);
    push_b(s_b, s_a);
    three_sort(s_a);
    move_el_to_a(s_a, s_b);
    move_el_to_a(s_a, s_b);
    slidetosort(s_a);
}
int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    t_stack *a;
    t_stack *b;
    int length;

    stack_a = parsing(argv, argc);
    stack_b = NULL;
    length = lst_len(stack_a);
    
    if(!is_sorted(stack_a))
    {
        if(length <= 5)
        {
            if (length == 2)
                rotate_a(&stack_a);
            else if (length == 3)
                three_sort(&stack_a);
            else if (length == 4)
                four_sort(&stack_a, &stack_b);
            else
                five_sort(&stack_a, &stack_b);
        }
        else
        {
            first_sort(&stack_a, &stack_b);
            second_sort(&stack_a, &stack_b);
            move_b_to_a(&stack_a, &stack_b);
        }
    }
    a = stack_a;
    b = stack_b;
    
    /*printf("\na\n");
    while(stack_a)
    {
        printf("%d\n", stack_a->value);
        stack_a = stack_a->next;
    }
    printf("\nb\n");
    while(stack_b)
    {
        printf("%d\n",stack_b->value);
        stack_b = stack_b->next;
    }*/
    
    free_lst(a);
    free_lst(b);
}


