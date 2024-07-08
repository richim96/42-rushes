/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:24:52 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 22:31:56 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/* Checks if the numeric string has only digits */
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/* Checks if file opens sucessfully */
int	ft_check_file_opens(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY | O_EXCL);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	close(fd);
	return (1);
}

/* Checks if command line arguments are valid */
int	ft_is_args_valid(int argc, char *argv[], char **dict, char *num)
{
	if (argc == 2)
	{
		num = argv[1];
	}
	else if (argc == 3)
	{
		*dict = argv[1];
		num = argv[2];
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ft_str_is_numeric(num))
		if (ft_check_file_opens(*dict))
			return (1);
	return (0);
}
