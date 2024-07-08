/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:04:37 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 21:04:55 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Matches the given digit to the word to write to stdout */
char	*ft_find_word(char ***dict, int n_keys, char *to_find)
{
	int		str_i;
	int		find_i;
	int		idx;

	str_i = 0;
	idx = 0;
	find_i = 0;
	while (str_i < n_keys)
	{
		while (to_find[find_i] && dict[str_i][0][idx]
			&& (to_find[find_i] == dict[str_i][0][idx]))
		{
			find_i++;
			idx++;
			if (!dict[str_i][0][idx] && !to_find[find_i])
			{
				return (dict[str_i][1]);
			}
		}
		str_i++;
		find_i = 0;
		idx = 0;
	}
	return (NULL);
}
