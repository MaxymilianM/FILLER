/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:06:28 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/10 17:06:29 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# define ZOOM 20

# include "../libprintf/ft_printf.h"
# include <mlx.h>

typedef struct			s_mw
{
	void				*mlx;
	void				*win;
	char				*p1;
	char				*p2;
	int					plato_x;
	int					plato_y;
	int					stop;
	char				*fin_x;
	char				*fin_o;
	int					winer;
}						t_mw;

void					ft_drow(t_mw *mlx_win, int ret);
void					ft_drow_screen(t_mw *mlx_win, int x_start, int y_start);
void					ft_drow_finish(t_mw *mlx_win);

#endif
