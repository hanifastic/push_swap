/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:59:40 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/19 19:08:11 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_before(t_list *list_b, int max)
{
	t_list	*temp;
	int		data;

	temp = list_b;
	if (temp->data != max)
		data = temp->data;
	else if (temp->data == max)
		data = temp->next->data;
	while (temp != NULL)
	{
		if (data < temp->data && temp->data < max)
			data = temp->data;
		temp = temp->next;
	}
	return (data);
}

int	ft_place(t_list **list_a, int data) //ok
{
	t_list	*temp;
	int		l;
	int		i;

	temp = *list_a;
	l = 1;
	i = 0;
	while (temp != NULL)
	{
		if (temp->data == data)
			i = l;
		temp = temp->next;
		l++;
	}
	return (i);
}

int	ft_lstmin(t_list *list_a) //ok
{
	int	min;

	min = list_a->data;
	while (list_a)
	{
		if (list_a->data < min)
			min = list_a->data;
		list_a = list_a->next;
	}
	return (min);
}

int	ft_lstmax(t_list *list_a) //ok
{
	int	max;

	max = list_a->data;
	while (list_a)
	{
		if (list_a->data > max)
			max = list_a->data;
		list_a = list_a->next;
	}
	return (max);
}

int	ft_lstsize(t_list *lst) //ok
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
