/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:54:08 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 20:08:26 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_lines_count(char *file_str);
char	*ft_take_num(char *file_str, int idx);
char	*ft_take_word(char *file_str, int idx);

void	ft_free_on_malloc_fail(char ***dict, int i)
{
	while (i-- > 0)
		free(dict[i]);
	free(dict);
}

/* Opens a file and returns a pointer to the string with its contents. Upon
failure, interrupts and returns NULL */
char	*ft_file_read(char *file_path)
{
	int		fd;
	int		fsize;
	char	*file_str;

	fd = open(file_path, O_RDONLY | O_EXCL);
	if (fd == -1)
		return (NULL);
	file_str = (char *) malloc(sizeof(char) * 5000);
	if (!file_str)
		return (NULL);
	fsize = read(fd, file_str, 5000);
	close(fd);
	if (fsize < 1)
		return (NULL);
	file_str[fsize] = '\0';
	return (file_str);
}

/* Initializes the 2D array */
char	***ft_dict_init(char *file_str)
{
	char	***dict;
	int		flines;
	int		i;

	flines = ft_lines_count(file_str);
	dict = (char ***) malloc(sizeof(char **) * flines);
	if (!dict)
		return (NULL);
	i = 0;
	while (i < flines)
	{
		dict[i] = (char **) malloc(sizeof(char *) * 2);
		if (!dict[i])
		{
			ft_free_on_malloc_fail(dict, i);
			return (NULL);
		}
		i++;
	}
	return (dict);
}

/* Maps the dictionary values to the 2D array; free file_str when done */
char	***ft_dict_make(char *file_path)
{
	char	*file_str;
	char	***dict;
	int		i;
	int		flines;

	file_str = ft_file_read(file_path);
	if (!file_str)
		return (NULL);
	dict = ft_dict_init(file_str);
	if (!dict)
		return (NULL);
	i = 0;
	flines = ft_lines_count(file_str);
	while (i < flines)
	{
		dict[i][0] = ft_take_num(file_str, i);
		dict[i][1] = ft_take_word(file_str, i);
		i++;
	}
	free(file_str);
	return (dict);
}
