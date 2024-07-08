/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:30:13 by kweihman          #+#    #+#             */
/*   Updated: 2024/02/21 20:27:43 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "globals.h"

void	ft_square_print(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_rows)
	{
		j = 0;
		while (j < g_cols)
		{
			if (j >= g_coord[1] && j < g_coord[1] + g_max_size
				&& i >= g_coord[0] && i < g_coord[0] + g_max_size)
			{
				write(1, &g_box, 1);
			}
			else
				write(1, &g_map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
