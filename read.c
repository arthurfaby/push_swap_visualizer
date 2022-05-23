/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:20:09 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 18:58:42 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	img_pixel_put(t_image *img, int y, int x, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len) + x * (img->bpp / 8);
	while (i >= 0)
	{
		if (img->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}	
}

void	draw_stack_a(t_env *env, t_stack *a)
{
	t_image	img;
	t_ll	*tmp;
	int		y;
	int		x;

	x = 0;
	img.img = mlx_new_image(env->mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	tmp = a->first;
	while (tmp)
	{
		y = 0;
		while (y < 500)
		{
			if (y < tmp->data)
				img_pixel_put(&img, x, y, 0xFF0000);
			else
				img_pixel_put(&img, x, y, 0);
			y++;
		}
		tmp = tmp->next;
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	mlx_destroy_image(env->mlx, img.img);
}

void	draw_stack_b(t_env *env, t_stack *b)
{
	t_image	img;
	t_ll	*tmp;
	int		y;
	int		x;

	x = 0;
	img.img = mlx_new_image(env->mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	tmp = b->first;
	while (tmp)
	{
		y = 0;
		while (y < 500)
		{
			if (y < tmp->data)
				img_pixel_put(&img, x, y, 0xFF0000);
			else
				img_pixel_put(&img, x, y, 0);
			y++;
		}
		tmp = tmp->next;
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, img.img, 510, 0);
	mlx_destroy_image(env->mlx, img.img);
}

void	draw_window(t_env *env, t_stack *a, t_stack *b)
{
	//mlx_clear_window(env->mlx, env->win);
	draw_stack_a(env, a);
	draw_stack_b(env, b);
}

void	switch_line(char *line, t_stack *a, t_stack *b)
{
	if (strcmp(line, "sa\n") == 0)
		sa(a);
	if (strcmp(line, "sb\n") == 0)
		sb(b);
	if (strcmp(line, "ss\n") == 0)
		ss(a, b);
	if (strcmp(line, "ra\n") == 0)
		ra(a);
	if (strcmp(line, "rb\n") == 0)
		rb(b);
	if (strcmp(line, "rr\n") == 0)
		rr(a, b);
	if (strcmp(line, "rra\n") == 0)
		rra(a);
	if (strcmp(line, "rrb\n") == 0)
		rrb(b);
	if (strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	if (strcmp(line, "pa\n") == 0)
		pa(a, b);
	if (strcmp(line, "pb\n") == 0)
		pb(a, b);
}

void	read_file(t_env *env, t_stack *a, t_stack *b, char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd, 1);
	while (line)
	{
		switch_line(line, a, b);
		draw_window(env, a, b);
		//usleep(30);
		free(line);
		line = get_next_line(fd, 1);
	}
}
