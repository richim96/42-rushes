/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:15:09 by rmei              #+#    #+#             */
/*   Updated: 2024/02/21 21:31:48 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "globals.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	ft_tables_init(void)
{
	g_map = (char **) malloc(sizeof(char *) * g_rows);
	g_dt = (int **) malloc(sizeof(int *) * g_rows);
	if (!g_map || !g_dt)
		return ;
	g_i = 0;
	while (g_i < g_rows)
	{
		g_map[g_i] = (char *) malloc(sizeof(char) * g_cols);
		g_dt[g_i] = (int *) malloc(sizeof(int) * g_cols);
		if (!g_map[g_i] || !g_dt[g_i])
		{
			while (g_i--)
			{
				free(g_map[g_i]);
				free(g_dt[g_i]);
			}
			free(g_map);
			free(g_dt);
			return ;
		}
		g_i++;
	}
}

void	ft_g_dt_fill(void)
{
	if (g_i == 0 || g_j == 0)
	{
		if (g_map[g_i][g_j] == g_block)
			g_dt[g_i][g_j] = 0;
		else
			g_dt[g_i][g_j] = 1;
	}
	else if (g_map[g_i][g_j] == g_block)
		g_dt[g_i][g_j] = 0;
	else
	{
		g_dt[g_i][g_j] = ft_min(
				g_dt[g_i - 1][g_j],
				g_dt[g_i][g_j - 1],
				g_dt[g_i - 1][g_j - 1]
				) + 1;
	}
}

void	ft_find_square(void)
{
	g_max_size = 0;
	g_i = 0;
	while (g_i < g_rows)
	{
		g_j = 0;
		while (g_j < g_cols)
		{
			ft_g_dt_fill();
			if (g_dt[g_i][g_j] > g_max_size)
			{
				g_max_size = g_dt[g_i][g_j];
				g_coord[0] = g_i - g_max_size + 1;
				g_coord[1] = g_j - g_max_size + 1;
			}
			g_j++;
		}
		g_i++;
	}
}
