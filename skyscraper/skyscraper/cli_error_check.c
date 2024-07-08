/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:37:37 by rmei              #+#    #+#             */
/*   Updated: 2024/02/10 17:16:15 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	return (c == ' ');
}

int	ft_is_digit(char c, int grid_size)
{
	return (c >= '0' && c <= grid_size + '0');
}

/* Returns 1 (true) if the input has the wrong format, 0 (false) otherwise. */
int	ft_is_not_format(char *str, int g)
{
	int		i;
	int		digit_count;
	char	c;

	i = 0;
	digit_count = 0;
	while (str[i])
	{
		c = str[i];
		if (i == 0 && !ft_is_digit(c, g))
			return (1);
		if (!ft_is_digit(c, g) && !ft_is_space(c))
			return (1);
		if (ft_is_digit(c, g) && !ft_is_space(str[i + 1]) && str[i + 1] != '\0')
			return (1);
		if (ft_is_space(c) && !ft_is_digit(str[i + 1], g))
			return (1);
		if (ft_is_digit(c, g))
			digit_count++;
		i++;
	}
	if (digit_count != 4 * g)
		return (1);
	return (0);
}
