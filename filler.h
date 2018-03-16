/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:24:33 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/04 12:24:34 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libprintf/ft_printf.h"

# define ABS(Value) Value < 0 ? -Value : Value

typedef struct		s_coord
{
	int				x;
	int				y;
	float			d;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_token
{
	char			player;
	int				plat_x;
	int				plat_y;
	int				piece_x;
	int				piece_y;
	int				len_sharp;
	int				*x_p;
	int				*y_p;
	int				opponent_x;
	int				opponent_y;
	char			**map;
	char			**piece;
	t_coord			*head;
	t_coord			*last;
}					t_token;

char				**ft_map(int fd, t_token *floop);
char				**ft_piece(int fd, t_token *floop);
void				ft_plato(int fd, t_token *floop);
void				ft_algo_start(t_token *floop);
void				ft_algo_result(t_token *floop);

#endif
