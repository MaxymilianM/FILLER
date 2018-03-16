/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:25:38 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/11 17:25:39 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static int		ft_parc_final(t_mw *mlx_win, int i)
{
	char		*s1;
	char		*s2;
	int			nb1;
	int			nb2;

	s1 = mlx_win->p1;
	s2 = mlx_win->p2;
	while (s1[i] != '\0' && s1[i] != 'p')
		i++;
	mlx_win->p1 = ft_strdup(s1 + i);
	mlx_win->p2 = ft_strdup(s2 + i);
	free(s1);
	free(s2);
	s1 = mlx_win->fin_x;
	s2 = mlx_win->fin_o;
	i = 0;
	while (!ft_isdigit(s1[i]) && s1[i] != '\0')
		i++;
	nb1 = ft_atoi(s1 + i);
	nb2 = ft_atoi(s2 + i);
	if (nb1 < nb2)
		return (1);
	return (2);
}

static void		ft_sec_win(t_mw *mlx_win)
{
	mlx_string_put(mlx_win->mlx, mlx_win->win, 410, 340,
		0x00FF00, mlx_win->p2);
	mlx_string_put(mlx_win->mlx, mlx_win->win, 350, 340,
		0x00FF00, "WIN: ");
	mlx_string_put(mlx_win->mlx, mlx_win->win, 410, 400,
		0x00FF00, mlx_win->p1);
	mlx_string_put(mlx_win->mlx, mlx_win->win, 350, 400,
		0x00FF00, "LOSE:");
}

void			ft_drow_finish(t_mw *mlx_win)
{
	int			p_win;

	mlx_clear_window(mlx_win->mlx, mlx_win->win);
	p_win = ft_parc_final(mlx_win, 0);
	ft_drow_screen(mlx_win, 200, 200);
	mlx_string_put(mlx_win->mlx, mlx_win->win, 410, 280,
		0x00FF00, mlx_win->fin_x);
	mlx_string_put(mlx_win->mlx, mlx_win->win, 410, 300,
		0x00FF00, mlx_win->fin_o);
	mlx_string_put(mlx_win->mlx, mlx_win->win, 400, 110,
		0x761AE4, "FILLER by: mminenko");
	if (p_win == 1)
	{
		mlx_string_put(mlx_win->mlx, mlx_win->win, 410, 340,
			0x00FF00, mlx_win->p1);
		mlx_string_put(mlx_win->mlx, mlx_win->win, 350, 340,
			0x00FF00, "WIN: ");
		mlx_string_put(mlx_win->mlx, mlx_win->win, 410, 400,
			0x00FF00, mlx_win->p2);
		mlx_string_put(mlx_win->mlx, mlx_win->win, 350, 400,
			0x00FF00, "LOSE:");
	}
	else
		ft_sec_win(mlx_win);
}
