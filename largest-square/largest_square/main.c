/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:14:56 by rmei              #+#    #+#             */
/*   Updated: 2024/02/21 22:29:51 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "globals.h"

/* Global variables */
int		g_i; // global indexer
int		g_j; // global indexer
int		g_coord[2]; // top-left coords to print the largest square
int		g_rows; // number of rows (starts at one)
int		g_cols; // number of columns (starts at one)
int		g_max_size; // max size of the square
int		**g_dt; // dynamic table to store the coords of largest square
char	**g_map; // map retaining data from the input file
char	g_box; // char for printing the square
char	g_block; // char for obstacles
char	g_empty; // char for empty positions

/* Function prototypes */
void	ft_g_map_fill(char *filepath, int is_filex);
void	ft_find_square(void);
void	ft_square_print(void);
int		ft_is_map_valid(void);

int	main(int argc, char **argv)
{
	int	is_file;

	is_file = 1;
	if (argc == 1 || argv[1][0] == '<')
		is_file = 0;
	ft_g_map_fill(argv[1], is_file);
	if (!ft_is_map_valid())
		return (1);
	ft_find_square();
	ft_square_print();
	return (0);
}
