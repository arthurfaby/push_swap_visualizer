/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:08:46 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 18:04:30 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_ll	*parse_stack_one_argument(char *str)
{
	t_ll	*a;
	t_ll	*temp;
	char	**args;
	int		i;

	i = 0;
	args = ft_split(str, ' ');
	if (!args)
		return (0);
	a = lstnew(ft_atoi(args[i++]));
	temp = a;
	while (args[i])
	{
		temp->next = lstnew(ft_atoi(args[i]));
		temp = temp->next;
		i++;
	}
	ft_free_double_pointer((void **)args);
	return (a);
}

t_ll	*parse_stack_multi_arguments(int n, char **argv)
{
	int		i;
	t_ll	*a;
	t_ll	*temp;

	i = 1;
	a = lstnew(ft_atoi(argv[i++]));
	temp = a;
	while (i < n)
	{
		temp->next = lstnew(ft_atoi(argv[i]));
		temp = temp->next;
		i++;
	}
	return (a);
}
