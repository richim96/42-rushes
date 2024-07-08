/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:57:05 by rmei              #+#    #+#             */
/*   Updated: 2024/02/11 23:33:50 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard_lib.h"

int	**ft_matrix_2d_init(int grid_size);
int	**ft_constraints_matrix_init(char *constraints, int grid_size);
int	ft_is_value_valid(int **matrix, int col_i, int row_i, int **cons_mtrx);

int	ft_not_double(int **matrix, int col_i, int row_i, int height)
{
	int	pos;

	pos = 0;
	while (pos < row_i)
	{
		if (matrix[pos][col_i] == height)
			return (0);
		pos++;
	}
	pos = 0;
	while (pos < col_i)
	{
		if (matrix[row_i][pos] == height)
			return (0);
		pos++;
	}
	return (1);
}

int	**ft_mtrx_solve(int **matrix, int **cons_mtrx, int col_i, int row_i)
{
	int	height;

	if (row_i == 3 && col_i == 3)
		return (matrix);
	height = 1;
	while (height <= 4)
	{
		if (ft_not_double(matrix, col_i, row_i, height))
		{
			matrix[row_i][col_i] = height;
			if (ft_is_value_valid(matrix, col_i, row_i, cons_mtrx))
			{
				if (col_i < 3)
					col_i++;
				if (col_i == 3 && row_i < 4)
					col_i = 0;
				if (ft_mtrx_solve(matrix, cons_mtrx, col_i, row_i))
					return (matrix);
			}
			else
				matrix[row_i][col_i] = 1;
		}
		height++;
	}
	return (NULL);
}

int	**ft_matrix_2d_fill(int grid_size, char *constraints)
{
	int	**matrix_2d;
	int	**matrix_test;
	int	**constraints_mtrx;
	int	col_i;
	int	row_i;

	col_i = 0;
	row_i = 0;
	matrix_2d = ft_matrix_2d_init(grid_size);
	constraints_mtrx = ft_constraints_matrix_init(constraints, grid_size);
	matrix_test = ft_mtrx_solve(matrix_2d, constraints_mtrx, col_i, row_i);
	if (!matrix_test)
		return (matrix_2d);
	return (matrix_test);
}

void	ft_matrix_2d_print(int **matrix_2d, int grid_size)
{
	int		i;
	int		j;
	char	n;

	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			n = matrix_2d[i][j] + '0';
			write(1, &n, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		free(matrix_2d[i]);
		i++;
	}
	free(matrix_2d);
}
