/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:59:17 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/21 14:41:14 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list_a)
{
	int	val;

	val = 0;
	if (ft_lstsize(*list_a) > 1)
	{
		val = (*list_a)->next->data;
		(*list_a)->next->data = (*list_a)->data;
		(*list_a)->data = val;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **list_b)
{
	int	val;

	val = 0;
	if (ft_lstsize(*list_b) > 1)
	{
		val = (*list_b)->next->data;
		(*list_b)->next->data = (*list_b)->data;
		(*list_b)->data = val;
		write(1, "sb\n", 3);
	}
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_b) > 0)
	{
		temp = (*list_b);
		*list_b = (*list_b)->next;
		temp->next = *list_a;
		*list_a = temp;
		temp = NULL;
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 0)
	{
		temp = (*list_a);
		*list_a = (*list_a)->next;
		temp->next = *list_b;
		*list_b = temp;
		temp = NULL;
		write(1, "pb\n", 3);
	}
}
