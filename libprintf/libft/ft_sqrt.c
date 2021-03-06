/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:04:04 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/14 14:04:06 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (n < nb / 2)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (0);
}
