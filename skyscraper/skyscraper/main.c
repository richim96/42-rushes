/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:49:47 by rmei              #+#    #+#             */
/*   Updated: 2024/02/11 23:17:09 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard_lib.h"

int		ft_is_not_format(char *str, int g);
int		**ft_matrix_2d_fill(int grid_size, char *constraints);
void	ft_matrix_2d_print(int **matrix_2d, int grid_size);

/* main() ensures input correctness before calling the solving function */
int	main(int argc, char **argv)
{
	char	*constraints;
	int		**matrix_2d;
	int		grid_size;

	grid_size = 4;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	constraints = argv[1];
	if (ft_is_not_format(constraints, grid_size))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	matrix_2d = ft_matrix_2d_fill(grid_size, constraints);
	if (!matrix_2d)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_matrix_2d_print(matrix_2d, grid_size);
	return (0);
}
