/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:17:28 by rmei              #+#    #+#             */
/*   Updated: 2024/02/21 22:30:29 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "globals.h"

/* Functions prototypes */
void	ft_strjoin(char *str, char *str_new);
void	ft_tables_init(void);
int		ft_cols_count(char *map_str);

/* Reads the map from file or standard input */
void	ft_file_read(char *filepath, char *str, int is_file)
{
	int		fd;
	int		fsize;
	int		buff;
	char	*str_temp;

	buff = 64;
	str_temp = (char *) malloc(sizeof(char) * buff);
	if (!str || !str_temp)
		return ;
	if (is_file)
		fd = open(filepath, O_RDONLY);
	else
		fd = STDIN_FILENO;
	if (fd == -1)
		return ;
	fsize = read(fd, str_temp, buff);
	while (fsize > 0 && fsize == buff)
	{
		ft_strjoin(str, str_temp);
		str_temp = (char *) malloc(sizeof(char) * buff); 
		fsize = read(fd, str_temp, buff);
	}
	close(fd);
	free(str_temp);
}

/* Determines if the first line of the map is valid and assigns the rules */
int	ft_map_rules_set(char *map)
{
	int	i;

	if (map[0] < '1' || map[0] > '9')
		return (0);
	i = 0;
	g_rows = 0;
	while (map[i] >= '0' && map[i] <= '9' && map[i + 3] != '\n')
	{
		g_rows = g_rows * 10 + (map[i] - '0');
		i++;
	}
	if (g_rows == 0)
		return (0);
	if (map[i] == map[i + 1] || map[i] == map[i + 2]
		|| map[i + 1] == map[i + 2])
		return (0);
	g_cols = ft_cols_count(map);
	g_empty = map[i];
	g_block = map[i + 1];
	g_box = map[i + 2];
	return (i + 4);
}

int	ft_map_start(char *filepath, char *map, int is_file)
{
	int	is_rules;

	ft_file_read(filepath, map, is_file);
	if (!map)
		return (0);
	is_rules = ft_map_rules_set(map);
	if (!is_rules)
		return (0);
	ft_tables_init();
	if (!g_map || !g_dt)
		return (0);
	return (is_rules);
}

/* While checking if the map's structure is valid, extracts map to 2D array */
void	ft_g_map_fill(char *filepath, int is_file)
{
	char	*map_str;
	int		i;

	map_str = (char *) malloc(sizeof(char));
	if (!map_str)
		return ;
	i = ft_map_start(filepath, map_str, is_file);
	if (!i)
		return ;
	g_i = 0;
	while (map_str[i])
	{
		g_j = 0;
		while (map_str[i] != '\n' && map_str[i] != '\0')
		{
			g_map[g_i][g_j] = map_str[i];
			i++;
			g_j++;
		}
		g_cols = g_j;
		i++;
		g_i++;
	}
	free(map_str);
}

int	ft_is_map_valid(void)
{
	int		i;
	int		j;
	char	chr;

	i = 0;
	while (g_map[i])
	{
		j = 0;
		while (g_map[i][j])
		{
			chr = g_map[i][j];
			if (chr != g_empty && chr != g_block && chr != g_box)
				return (0);
			j++;
		}
		if (j != g_cols)
			return (0);
		j = 0;
		while (g_map[i][j] != g_empty)
			j++;
		if (!g_map[i + 1] && g_map[i][j] != g_empty)
			return (0);
		i++;
	}
	return (1);
}
