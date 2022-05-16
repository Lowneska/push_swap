/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:21:49 by skhali            #+#    #+#             */
/*   Updated: 2022/05/16 05:02:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	rrotate(t_stack **st)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	
	tmp = *st;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *st;
	tmp2 = tmp->next;
	tmp->next = NULL;
	*st = tmp2;
}

void	rrotate_a(t_stack **st)
{
	rrotate(st);
	ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_stack **st)
{
	rrotate(st);
	ft_putstr_fd("rrb\n", 1);
}

void	rrotate_r(t_stack **sta, t_stack **stb)
{
	rrotate(sta);
	rrotate(stb);
	ft_putstr_fd("rrr\n", 1);
}
