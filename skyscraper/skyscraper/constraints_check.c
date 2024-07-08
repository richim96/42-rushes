/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:29:56 by rmei              #+#    #+#             */
/*   Updated: 2024/02/11 23:11:54 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard_lib.h"

int	ft_not_valid_col_up(int **matrix, int col_i, int row_i, int *c_up)
{
	int	i;
	int	max_height;
	int	views;

	if (row_i == 0)
	{
		i = 0;
		max_height = 0;
		views = 0;
		while (i < 4)
		{
			if (matrix[i][col_i] > max_height)
			{
				max_height = matrix[i][col_i];
				views++;
			}
			i++;
		}
		if (views != c_up[col_i])
			return (1);
	}
	return (0);
}

int	ft_not_valid_col_down(int **matrix, int col_i, int row_i, int *c_down)
{
	int	i;
	int	max_height;
	int	views;

	if (row_i == 3)
	{
		i = 3;
		max_height = 0;
		views = 0;
		while (i >= 0)
		{
			if (matrix[i][col_i] > max_height)
			{
				max_height = matrix[i][col_i];
				views++;
			}
			i--;
		}
		if (views != c_down[col_i])
			return (1);
	}
	return (0);
}

int	ft_not_valid_row_left(int **matrix, int col_i, int row_i, int *r_left)
{
	int	i;
	int	max_height;
	int	views;

	if (col_i == 0)
	{
		i = 0;
		max_height = 0;
		views = 0;
		while (i < 4)
		{
			if (matrix[row_i][i] > max_height)
			{
				max_height = matrix[row_i][i];
				views++;
			}
			i++;
		}
		if (views != r_left[row_i])
			return (1);
	}
	return (0);
}

int	ft_not_valid_row_right(int **matrix, int col_i, int row_i, int *r_right)
{
	int	i;
	int	max_height;
	int	views;

	if (col_i == 3)
	{
		i = 3;
		max_height = 0;
		views = 0;
		while (i >= 0)
		{
			if (matrix[row_i][i] > max_height)
			{
				max_height = matrix[row_i][i];
				views++;
			}
			i--;
		}
		if (views != r_right[row_i])
			return (1);
	}
	return (0);
}

int	ft_is_value_valid(int **matrix, int col_i, int row_i, int **cons_mtrx)
{
	if (ft_not_valid_col_up(matrix, col_i, row_i, cons_mtrx[0]))
		return (0);
	if (ft_not_valid_col_down(matrix, col_i, row_i, cons_mtrx[1]))
		return (0);
	if (ft_not_valid_row_left(matrix, col_i, row_i, cons_mtrx[2]))
		return (0);
	if (ft_not_valid_row_right(matrix, col_i, row_i, cons_mtrx[3]))
		return (0);
	return (1);
}
