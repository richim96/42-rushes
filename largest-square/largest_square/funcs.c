/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:17:18 by rmei              #+#    #+#             */
/*   Updated: 2024/02/21 21:42:51 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strjoin(char *str, char *str_new)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (str_new[j])
	{
		str[i] = str_new[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

int	ft_cols_count(char *map_str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map_str[i] != '\n')
		i++;
	i++;
	while (map_str[i] != '\n')
	{
		count++;
		i++;
	}
	return (count);
}
