/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:19:43 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/04 16:19:45 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_coor_piece(char *line, t_token *floop)
{
	while (!(ft_isdigit(*line)))
		line++;
	floop->piece_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	floop->piece_x = ft_atoi(line);
}

static char		*ft_line_purs(char *line, t_token *floop)
{
	char *gen;

	gen = ft_strnew(floop->plat_x);
	gen = ft_strcpy(gen, line);
	return (gen);
}

char			**ft_piece(int fd, t_token *floop)
{
	char		**piece;
	char		*line;
	int			ret;
	int			i;

	ret = get_next_line(fd, &line);
	ft_coor_piece(line, floop);
	i = 0;
	piece = (char **)malloc(sizeof(char *) * (floop->piece_y + 1));
	(ret > 0) ? free(line) : 0;
	while ((i < (floop->piece_y)) && (ret > 0))
	{
		ret = get_next_line(fd, &line);
		piece[i] = ft_line_purs(line, floop);
		(ret > 0) ? free(line) : 0;
		i++;
	}
	piece[i] = NULL;
	return (piece);
}
