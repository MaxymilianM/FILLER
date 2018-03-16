/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:33:49 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/06 14:33:50 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static float	ft_rsqrt(float number)
{
	long		i;
	float		x2;
	float		y;
	float		threehalfs;

	threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return (1 / y);
}

static void		ft_find_opponent(t_token *floop)
{
	int			x;
	int			y;
	char		opnt;

	opnt = (floop->player == 'O') ? 'X' : 'O';
	y = 0;
	floop->opponent_x = (floop->plat_x / 2);
	floop->opponent_y = (floop->plat_y / 2);
	while (floop->map[y] != NULL)
	{
		x = 0;
		while (floop->map[y][x] != '\0')
		{
			if (floop->map[y][x] == (opnt + 32))
			{
				floop->opponent_x = x;
				floop->opponent_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

static void		ft_find_best_distants(t_token *floop, int u, t_coord *list)
{
	float		d_min;
	int			i;

	i = 0;
	list = floop->head;
	d_min = list->d;
	while (list != NULL)
	{
		if (d_min > list->d)
		{
			d_min = list->d;
			u = i;
		}
		list = list->next;
		i++;
	}
	i = 0;
	list = floop->head;
	while (i < u && list != NULL)
	{
		list = list->next;
		i++;
	}
	ft_printf("%d %d\n", list->y, list->x);
}

static void		ft_best_distants(t_token *floop)
{
	int			tmp1;
	int			tmp2;
	t_coord		*list;

	if (floop->head == NULL)
		return ;
	list = floop->head;
	while (list != NULL)
	{
		tmp1 = (floop->opponent_x) * (floop->opponent_x) - 2 *
			(floop->opponent_x) * (list->x) + (list->x) * (list->x);
		tmp2 = (floop->opponent_y) * (floop->opponent_y) - 2 *
			(floop->opponent_y) * (list->y) + (list->y) * (list->y);
		list->d = ft_rsqrt(tmp1 + tmp2);
		list = list->next;
	}
	ft_find_best_distants(floop, 0, NULL);
}

void			ft_algo_result(t_token *floop)
{
	ft_find_opponent(floop);
	ft_best_distants(floop);
}
