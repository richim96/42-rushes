/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_triples.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:10:22 by eduribei          #+#    #+#             */
/*   Updated: 2024/02/18 22:46:48 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

void	ft_free_malloc_fail(char ***triples, int i)
{
	while (i-- > 0)
		free(triples[i]);
	free(triples);
}

char	***ft_triples_init(char ***triples, int n_triples)
{
	int	i;

	triples = (char ***) malloc(sizeof(char **) * n_triples);
	if (!triples)
		return (NULL);
	i = 0;
	while (i < n_triples)
	{
		triples[i] = (char **) malloc(sizeof(char *) * 4);
		if (!triples[i])
		{
			ft_free_malloc_fail(triples, i);
			return (NULL);
		}
		i++;
	}
	return (triples);
}

char	*add_zeros(char *number)
{
	int		extra_zeros;
	int		i;
	int		len;
	char	*new_str;

	extra_zeros = 0;
	i = 0;
	len = ft_strlen(number);
	if (len % 3 == 1)
		extra_zeros = 2;
	else if (len % 3 == 2)
		extra_zeros = 1;
	new_str = (char *) malloc(sizeof(char) * (len + extra_zeros + 1));
	if (!new_str)
		return (NULL);
	while (i < extra_zeros)
	{
		new_str[i] = '0';
		i++;
	}
	ft_strcpy(new_str + i, number);
	return (new_str);
}

char	***ft_place_numbers(char ***triples, char *final_number, int n_triples)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < n_triples)
	{
		j = 0;
		while (j < 3)
		{
			triples[i][j] = &final_number[k];
			k++;
			j++;
		}
		triples[i][j] = "\0";
		i++;
	}
	return (triples);
}

char	***ft_create_triples(char *string_nbr)
{
	int		n_triples;
	char	***triples;
	char	*final_nbr;

	if (ft_strlen(string_nbr) % 3 == 0)
		n_triples = (ft_strlen(string_nbr) / 3);
	else
		n_triples = ((ft_strlen(string_nbr) / 3) + 1);
	ft_triples_init(triples, n_triples);
	final_nbr = add_zeros(string_nbr);
	ft_place_numbers(triples, final_nbr, n_triples);
	free(final_nbr);
	return (triples);
}
/*
int	main(void)
{
	char *string_number = "4857";
    	char	***triples;

	triples = ft_create_triples(string_number);
	printf("%s", triples[1][0]);
}
*/
