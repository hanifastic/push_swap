/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:00:02 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/19 19:08:15 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_reverse(t_list **list_b) //ok
{
	int	min;
	int	max;
	int	i;

	min = ft_lstmin(*list_b);
	max = ft_lstmax(*list_b);
	i = ft_lstsize(*list_b);
	while (i > 1)
	{
		if ((*list_b)->data == min && (*list_b)->next->data != max)
			sb(list_b);
		if ((*list_b)->data != min && (*list_b)->next->data == max)
			sb(list_b);
		if ((*list_b)->data != max && (*list_b)->next->data == min)
			rrb(list_b);
		if ((*list_b)->data == min && (*list_b)->next->data == max)
			rb(list_b);
		if ((*list_b)->data == max && (*list_b)->next->data == min && i != 2)
			rrb(list_b);
		i--;
	}
}

int	ft_push_a_limit_vol_2(t_list **list_a, t_list **list_b, int max, int i)
{
	int	max_place;
	int	max_before;
	int	size;

	max_place = ft_place(list_b, max);
	max_before = ft_max_before(*list_b, max);
	size = ft_lstsize(*list_b);
	max_place = size - max_place + 1;
	while (max_place-- > 0)
	{
		if ((*list_b)->data == max_before && max_before != max)
		{
			pa(list_a, list_b);
			ra(list_a);
			i++;
			max_place = max_place + 1;
		}
		else
			rrb(list_b);
	}
	pa(list_a, list_b);
	return (i);
}

int	ft_push_a_limit_vol_1(t_list **list_a, t_list **list_b, int max, int i)
{
	int	max_place;
	int	max_before;

	max_place = ft_place(list_b, max);
	max_before = ft_max_before(*list_b, max);
	max_place = max_place - 1;
	while (max_place-- > 0)
	{
		if ((*list_b)->data == max_before && max_before != max)
		{
			pa(list_a, list_b);
			ra(list_a);
			i++;
		}
		else
			rb(list_b);
	}
	pa(list_a, list_b);
	return (i);
}

void	ft_push_a(t_list **list_a, t_list **list_b)
{
	int	place;
	int	i;
	int	max;

	max = ft_lstmax(*list_b);
	place = ft_lstsize(*list_b) / 2;
	i = 0;
	if (place > ft_place(list_b, max))
	{
		i = i + ft_push_a_limit_vol_1(list_a, list_b, max, i);
	}
	else if (place <= ft_place(list_b, max))
	{
		i = i + ft_push_a_limit_vol_2(list_a, list_b, max, i);
	}
	while (i-- > 0)
		rra(list_a);
}
