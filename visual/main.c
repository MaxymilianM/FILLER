/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:05:38 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/10 17:05:40 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void		ft_build_window(t_mw *mlx_win, int ret, char *line)
{
	char		*line_2;

	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ft_strstr(line, "$$$"))
		{
			if (ft_strstr(line, "p1"))
				mlx_win->p1 = ft_strdup(line);
			else
				mlx_win->p2 = ft_strdup(line);
		}
		else if (ft_strstr(line, "Plateau"))
			break ;
		(ret > 0) ? free(line) : 0;
	}
	line_2 = line;
	while (!(ft_isdigit(*line)) && line)
		line++;
	mlx_win->plato_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	mlx_win->plato_x = ft_atoi(line);
	(ret > 0) ? free(line_2) : 0;
}

static int		my_key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

static int		my_function(t_mw *mlx_win)
{
	if (mlx_win->stop == 0)
		ft_drow(mlx_win, 1);
	else
		ft_drow_finish(mlx_win);
	return (0);
}

static void		ft_window(t_mw *mlx_win)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1400, 1200, "visualizer 3000");
	mlx_win->mlx = mlx;
	mlx_win->win = win;
}

int				main(void)
{
	t_mw		mlx_win;

	mlx_win.fin_o = 0;
	mlx_win.fin_x = 0;
	mlx_win.stop = 0;
	ft_build_window(&mlx_win, 1, NULL);
	ft_window(&mlx_win);
	mlx_key_hook(mlx_win.win, my_key_funct, &mlx_win);
	mlx_loop_hook(mlx_win.mlx, my_function, &mlx_win);
	mlx_loop(mlx_win.mlx);
	return (0);
}
