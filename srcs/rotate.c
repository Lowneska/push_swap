/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:59:10 by skhali            #+#    #+#             */
/*   Updated: 2022/05/16 05:02:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	rotate(t_stack **st)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *st;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*st);
	tmp2 = (*st)->next;
	(*st)->next = NULL;
	*st = tmp2;
}

void	rotate_a(t_stack **st)
{
	rotate(st);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **st)
{
	rotate(st);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_r(t_stack **sta, t_stack **stb)
{
	rotate(sta);
	rotate(stb);
	ft_putstr_fd("rr\n", 1);
}