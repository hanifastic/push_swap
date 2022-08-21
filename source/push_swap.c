/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:59:04 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/21 14:41:15 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushing_b(t_list **list_a, t_list **list_b)
{
	while (ft_lstsize(*list_a) > 3)
		ft_push_b(list_a, list_b, 0, 0);
	ft_three(list_a);
}

void	ft_pushing_a(t_list **list_a, t_list **list_b)
{
	int	size;

	size = 0;
	while (ft_lstsize(*list_b) > 3)
		ft_push_a(list_a, list_b);
	ft_three_reverse(list_b);
	size = ft_lstsize(*list_b);
	while (size-- > 0)
		pa(list_a, list_b);
}

void	ft_big_numbers(t_list **list_a, t_list **list_b)
{
	ft_pushing_b(list_a, list_b);
	ft_pushing_a(list_a, list_b);
}

void	ft_push_swap(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) < 4)
		ft_three(list_a);
	else if (ft_lstsize(*list_a) < 11)
		ft_ten(list_a, list_b);
	else
		ft_big_numbers(list_a, list_b);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc > 1)
	{
		argc = argc - 1;
		argv++;
		argv = ft_one_line_arguments(argc, argv);
		argc = ft_one_line_argc(argc, argv);
		ft_string_check(argc, argv);
		while (argc--)
			list_a = ft_argv_to_list(list_a, argv[argc]);
		if (ft_place_check(list_a))
			ft_exit(0);
		else
			ft_push_swap(&list_a, &list_b);
		ft_free(&list_a);
	}
	ft_exit(0);
}
