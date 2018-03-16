/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:38:06 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/10 17:38:07 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		ft_drow_screen(t_mw *mlx_win, int x_start, int y_start)
{
	int		x_fin;
	int		y_fin;

	x_fin = x_start + mlx_win->plato_x * ZOOM + ZOOM;
	y_fin = y_start + mlx_win->plato_y * ZOOM + ZOOM;
	while (y_start < y_fin)
	{
		mlx_pixel_put(mlx_win->mlx, mlx_win->win, x_start, y_start, 0x00FFFF00);
		y_start++;
	}
	while (x_start < x_fin)
	{
		mlx_pixel_put(mlx_win->mlx, mlx_win->win, x_start, y_start, 0x00FFFFFF);
		x_start++;
	}
	while (y_start > 200)
	{
		mlx_pixel_put(mlx_win->mlx, mlx_win->win, x_start, y_start, 0x00FF00FF);
		y_start--;
	}
	while (x_start > 200)
	{
		mlx_pixel_put(mlx_win->mlx, mlx_win->win, x_start, y_start, 0x0000FFFF);
		x_start--;
	}
}

static void	ft_line_parc(char *line, t_mw *mlx_win, int *y1)
{
	int		x;
	int		tmp;
	int		y;

	if (*line != '0')
		return ;
	while (*line && *line != '.' && *line != 'X' &&
		*line != 'x' && *line != 'O' && *line != 'o')
		line++;
	(*y1)++;
	y = *y1;
	y = 200 + y * ZOOM;
	x = 200;
	tmp = 200 + mlx_win->plato_x * ZOOM;
	while (x < tmp)
	{
		x += ZOOM;
		if (*line == 'O' || *line == 'o')
			mlx_pixel_put(mlx_win->mlx, mlx_win->win, x, y, 0x000000FA);
		else if (*line == 'X' || *line == 'x')
			mlx_pixel_put(mlx_win->mlx, mlx_win->win, x, y, 0x00FF0000);
		line++;
	}
}

static void	ft_finish(int ret, char *line, t_mw *mlx_win)
{
	int		i;

	i = 0;
	mlx_win->stop = 1;
	while (line[i] != 'O' && line[i] != '\0')
		i++;
	mlx_win->fin_o = ft_strdup(line + i);
	(ret > 0) ? free(line) : 0;
	i = 0;
	ret = get_next_line(0, &line);
	while (line[i] != 'X' && line[i] != '\0')
		i++;
	mlx_win->fin_x = ft_strdup(line + i);
	(ret > 0) ? free(line) : 0;
}

void		ft_drow(t_mw *mlx_win, int ret)
{
	char	*line;
	int		y;

	y = 0;
	mlx_clear_window(mlx_win->mlx, mlx_win->win);
	ft_drow_screen(mlx_win, 200, 200);
	mlx_string_put(mlx_win->mlx, mlx_win->win, 400, 110,
		0x761AE4, "FILLER by: mminenko");
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ft_strstr(line, "=="))
		{
			ft_finish(ret, line, mlx_win);
			break ;
		}
		if (ft_strstr(line, "got"))
		{
			y = 0;
			(ret > 0) ? free(line) : 0;
			break ;
		}
		(*line == 48) ? ft_line_parc(line, mlx_win, &y) : 0;
		(ret > 0) ? free(line) : 0;
	}
}
