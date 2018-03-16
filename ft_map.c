/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:19:28 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/04 16:19:31 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_plato(int fd, t_token *floop)
{
	int			ret;
	char		*line;
	char		*line_2;

	ret = get_next_line(fd, &line);
	line_2 = line;
	while (!(ft_isdigit(*line)))
		line++;
	floop->plat_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	floop->plat_x = ft_atoi(line);
	(ret > 0) ? free(line_2) : 0;
}

static char		*ft_line_gen(char *line, t_token *floop)
{
	char		*gen;

	gen = ft_strnew(floop->plat_x);
	while (*line && *line != '.' && *line != 'X' &&
		*line != 'x' && *line != 'O' && *line != 'o')
		line++;
	gen = ft_strcpy(gen, line);
	return (gen);
}

char			**ft_map(int fd, t_token *floop)
{
	char		**map;
	char		*line;
	int			ret;
	int			i;

	i = 0;
	ft_plato(fd, floop);
	map = (char **)malloc(sizeof(char *) * (floop->plat_y + 1));
	ret = get_next_line(fd, &line);
	(ret > 0) ? free(line) : 0;
	while ((i < (floop->plat_y)) && (ret > 0))
	{
		ret = get_next_line(fd, &line);
		map[i] = ft_line_gen(line, floop);
		(ret > 0) ? free(line) : 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}
