/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:33:22 by skhali            #+#    #+#             */
/*   Updated: 2022/05/16 05:02:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	swap(t_stack **st)
{
	int	tmp;

	tmp = (*st)->value;
	(*st)->value = (*st)->next->value;
	(*st)->next->value = tmp;
}

void	swap_a(t_stack **st)
{
    swap(st);
    ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack **st)
{
    swap(st);
    ft_putstr_fd("sb\n", 1);
}
