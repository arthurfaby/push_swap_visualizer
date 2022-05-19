/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:38:54 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 18:05:08 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_image
{
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;
	void	*img;
}	t_image;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_env;

typedef struct s_ll
{
	int			data;
	struct s_ll	*next;
}	t_ll;

typedef struct s_stack
{
	t_ll	*first;
}	t_stack;

// PUSH.C

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// SWAP.C


void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// ROTATE.C

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// REVERSE_ROTATE.C

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// PARSE.C

t_ll	*parse_stack_one_argument(char *str);
t_ll	*parse_stack_multi_arguments(int n, char **argv);

// READ.C


void	img_pixel_put(t_image *img, int y, int x, int color);
void	draw_stack_a(t_env *env, t_stack *a);
void	draw_stack_b(t_env *env, t_stack *b);
void	draw_window(t_env *env, t_stack *a, t_stack *b);
void	switch_line(char *line, t_stack *a, t_stack *b);
void	read_file(t_env *env, t_stack *a, t_stack *b, char *path);

// LST.C

t_ll	*lstnew(int data);

#endif
