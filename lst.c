/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:39:38 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 18:05:36 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_ll	*lstnew(int data)
{
	t_ll	*new;

	new = malloc(sizeof(t_ll));
	if (!new)
		return (0);
	new->data = data;
	new->next = NULL;
	return (new);
}
