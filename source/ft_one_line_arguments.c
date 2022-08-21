/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_line_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:00:07 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/21 14:41:09 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	wordcount(char const *s, char c) //ok
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static char	*stringf(const char *s, char c) //ok
{
	char	*temp;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(const char *s, char c) //ok
{
	char	**temp;
	int		wordc;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	wordc = wordcount(s, c);
	temp = (char **)malloc(sizeof(char *) * (wordc + 1));
	if (!temp)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			temp[i] = stringf(s, c);
			i++;
		}
		while (*s && *s != c)
		s++;
	}
	temp[i] = NULL;
	return (temp);
}

char	**ft_one_line_arguments(int argc, char **argv) //ok
{
	if (argc == 1)
		argv = ft_split(*argv, ' ');
	return (argv);
}

int	ft_one_line_argc(int argc, char **argv) //ok
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		while (argv[i] != NULL)
			i++;
		if (argv[i] == NULL)
		{
			return (i);
		}
	}
	return (argc);
}
