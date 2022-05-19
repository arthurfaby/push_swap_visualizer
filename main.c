/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:37:07 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 18:17:53 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	parse_wh(t_env *env)
{
	char	*line;
	int		fd;

	fd = open("config.ini", O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd, 1);
	env->width = ft_atoi(line);
	free(line);
	line = get_next_line(fd, 1);
	env->height = ft_atoi(line);
	free(line);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (printf("\033[0;31mUsage error :\033[0m %s args\n", argv[0]));
	if (argc == 2)
		a.first = parse_stack_one_argument(argv[1]);
	else
		a.first = parse_stack_multi_arguments(argc, argv);
	b.first = NULL;
	env.mlx = mlx_init();
	parse_wh(&env);
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Visualizer");
	//draw_window(&env, &a, &b);
	read_file(&env, &a, &b, "moves");
	mlx_loop(env.mlx);
	(void)a;
	(void)b;
	(void)argc;
	(void)argv;
}
