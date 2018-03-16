/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:16:36 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/04 18:16:38 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_good_coord(t_token *floop, int len)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	y = 0;
	floop->x_p = (int*)malloc(sizeof(int) * len);
	floop->y_p = (int*)malloc(sizeof(int) * len);
	while (floop->piece[y] != NULL)
	{
		x = 0;
		while (floop->piece[y][x] != '\0')
		{
			if (floop->piece[y][x] == '*')
			{
				floop->x_p[i] = x;
				floop->y_p[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void		ft_piece_of_strategy(t_token *floop)
{
	int			x;
	int			y;

	y = 0;
	floop->len_sharp = 0;
	while (floop->piece[y] != NULL)
	{
		x = 0;
		while (floop->piece[y][x] != '\0')
		{
			(floop->piece[y][x] == '*') ? floop->len_sharp++ : 0;
			x++;
		}
		y++;
	}
	ft_good_coord(floop, floop->len_sharp);
}

static void		ft_save_good_coord(t_token *floop, int x, int y)
{
	t_coord		*new;

	new = (t_coord*)malloc(sizeof(t_coord));
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (floop->head == NULL)
	{
		floop->head = new;
		floop->last = new;
	}
	else
	{
		floop->last->next = new;
		floop->last = floop->last->next;
	}
}

static void		ft_check_position(t_token *floop, int x, int y, int u)
{
	int			i;
	int			x_y[2];
	int			x_y_h[2];

	x_y_h[0] = x;
	x_y_h[1] = y;
	while (++u < floop->len_sharp)
	{
		x_y[0] = x_y_h[0] - floop->x_p[u];
		x_y[1] = x_y_h[1] - floop->y_p[u];
		i = -1;
		while (++i < floop->len_sharp)
		{
			if (i == u)
				continue ;
			x = x_y[0] + floop->x_p[i];
			y = x_y[1] + floop->y_p[i];
			if (x < 0 || y < 0 || y >= floop->plat_y ||
				x >= floop->plat_x || floop->map[y][x] != '.')
				break ;
		}
		(i == floop->len_sharp) ? ft_save_good_coord(floop, x_y[0], x_y[1]) : 0;
	}
}

void			ft_algo_start(t_token *floop)
{
	int			x;
	int			y;

	y = 0;
	ft_piece_of_strategy(floop);
	while (y < floop->plat_y)
	{
		x = 0;
		while (x < floop->plat_x)
		{
			if ((floop->map[y][x] == floop->player) ||
				(floop->map[y][x] == (floop->player + 32)))
			{
				ft_check_position(floop, x, y, -1);
			}
			x++;
		}
		y++;
	}
	if (floop->head == NULL)
	{
		ft_printf("%d %d\n", 0, 0);
		exit(0);
	}
	ft_algo_result(floop);
}
