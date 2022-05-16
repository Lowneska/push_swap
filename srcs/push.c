/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:26:26 by skhali            #+#    #+#             */
/*   Updated: 2022/05/16 05:08:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	push(t_stack **stackb, t_stack **stacka)
{
	if(!stackb)
	{
		ft_putstr_fd("Erreur\n", 2);
		exit(EXIT_FAILURE);
	}
	t_stack	*cur;

	cur = *stacka;
	*stacka = cur->next;
	cur->next = *stackb;
	*stackb = cur;
}

void	push_a(t_stack **stackb, t_stack **stacka)
{
	push(stacka, stackb);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack **stackb, t_stack **stacka)
{
	push(stackb, stacka);
	ft_putstr_fd("pb\n", 1);
}