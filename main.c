/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:24:40 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/04 12:24:42 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			ft_get_player(int fd, t_token *floop)
{
	char			*line;
	int				ret;

	ret = get_next_line(fd, &line);
	if (ret == 0)
		exit(0);
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
			floop->player = 'O';
		else if (ft_strstr(line, "p2"))
			floop->player = 'X';
	}
	(ret > 0) ? free(line) : 0;
}

static void			ft_clean2(t_token *floop)
{
	t_coord			*dell;

	while (floop->head != NULL)
	{
		dell = floop->head;
		floop->head = floop->head->next;
		free(dell);
	}
	floop->head = NULL;
	floop->last = NULL;
}

static void			ft_clean_all(t_token *floop)
{
	int				i;

	i = 0;
	free(floop->x_p);
	free(floop->y_p);
	floop->x_p = NULL;
	floop->y_p = NULL;
	while (floop->map[i] != NULL)
	{
		ft_strdel(&floop->map[i]);
		i++;
	}
	free(floop->map);
	floop->map = NULL;
	i = 0;
	while (floop->piece[i] != NULL)
	{
		ft_strdel(&floop->piece[i]);
		i++;
	}
	free(floop->piece);
	floop->piece = NULL;
	ft_clean2(floop);
}

int					main(void)
{
	t_token			floop;
	int				fd;

	fd = 0;
	ft_get_player(fd, &floop);
	while (1)
	{
		floop.map = ft_map(fd, &floop);
		floop.piece = ft_piece(fd, &floop);
		floop.head = NULL;
		floop.last = NULL;
		ft_algo_start(&floop);
		ft_clean_all(&floop);
	}
	return (0);
}
