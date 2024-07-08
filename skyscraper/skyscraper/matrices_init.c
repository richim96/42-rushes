/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:19 by nboer             #+#    #+#             */
/*   Updated: 2024/02/11 23:32:18 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard_lib.h"

void	ft_write_malloc_error(void)
{
	char	*malloc_fail_msg;

	malloc_fail_msg = "Malloc failure on matrix initialization\n";
	write(2, malloc_fail_msg, sizeof(malloc_fail_msg) - 1);
}

void	ft_free_matrices_on_fail(int **matrix_2d, int i)
{
	while (i-- > 0)
		free(matrix_2d[i]);
	free(matrix_2d);
	ft_write_malloc_error();
}

void	ft_matrix_1d_fill(int **matrix_2d, int i, int size, char *constraints)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < size)
	{
		if (constraints)
			matrix_2d[i][j] = constraints[k] - '0';
		else
			matrix_2d[i][j] = j + 1;
		k += 2;
		j++;
	}
}

/* Initializes 2D matrix representing the given grid */
int	**ft_matrix_2d_init(int grid_size)
{
	int	**matrix_2d;
	int	i;

	matrix_2d = (int **) malloc(sizeof(int *) * grid_size);
	if (!matrix_2d)
	{
		ft_write_malloc_error();
		return (NULL);
	}
	i = 0;
	while (i < grid_size)
	{
		matrix_2d[i] = (int *) malloc(sizeof(int) * grid_size);
		if (!matrix_2d[i])
		{
			ft_free_matrices_on_fail(matrix_2d, i);
			return (NULL);
		}
		ft_matrix_1d_fill(matrix_2d, i, grid_size, NULL);
		i++;
	}
	return (matrix_2d);
}

/* Initializes 2D matrix with the constraints given to fill the grid*/
int	**ft_constraints_matrix_init(char *constraints, int grid_size)
{
	int	**constraints_matrix;
	int	i;

	constraints_matrix = (int **) malloc(sizeof(int *) * grid_size);
	if (!constraints_matrix)
	{
		ft_write_malloc_error();
		return (NULL);
	}
	i = 0;
	while (i < grid_size && *constraints)
	{
		constraints_matrix[i] = (int *) malloc(sizeof(int) * grid_size);
		if (!constraints_matrix[i])
		{
			ft_free_matrices_on_fail(constraints_matrix, i);
			return (NULL);
		}
		ft_matrix_1d_fill(constraints_matrix, i, grid_size, constraints);
		constraints += 2 * grid_size;
		i++;
	}
	return (constraints_matrix);
}
