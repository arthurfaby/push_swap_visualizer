/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:01:53 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 17:17:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	rra(t_stack *a)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = a->first;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp2->next = a->first;
	a->first = tmp2;
	tmp->next = NULL;
}

void	rrb(t_stack *b)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = b->first;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp2->next = b->first;
	b->first = tmp2;
	tmp->next = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
