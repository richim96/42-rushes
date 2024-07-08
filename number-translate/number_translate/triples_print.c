/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triples_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:56:07 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 21:06:14 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_find_word(char ***dict, int n_keys, char *to_find);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* Prints the first digit of the triple */
void	ft_first_digit_write(char ***dict, char *digits, int n_keys)
{
	char	tmp_digit[2];
	char	*word;

	if (digits[0] == '0')
		return ;
	tmp_digit[0] = digits[0];
	tmp_digit[1] = '\0';
	word = ft_find_word(dict, n_keys, tmp_digit);
	ft_putstr(word);
	write(1, " ", 1);
	word = ft_find_word(dict, n_keys, "100");
	ft_putstr(word);
	write(1, " ", 1);
}

/* Prints the second digit of the triple */
void	ft_second_digit_write(char ***dict, char *digits, int n_keys)
{
	char	tmp_digit[3];
	char	*word;

	if (digits[1] == '0')
		return ;
	tmp_digit[0] = digits[1];
	if (tmp_digit[0] == '1')
		tmp_digit[1] = digits[2];
	else
		tmp_digit[1] = '0';
	tmp_digit[2] = '\0';
	word = ft_find_word(dict, n_keys, tmp_digit);
	ft_putstr(word);
	write(1, " ", 1);
}

/* Prints the third and last digit of the triple */
void	ft_third_digit_write(char ***dict, char *digits, int n_keys)
{
	char	tmp_digit[2];
	char	*word;

	if (digits[2] == '0' || digits[1] == '1')
		return ;
	tmp_digit[0] = digits[2];
	tmp_digit[1] = '\0';
	word = ft_find_word(dict, n_keys, tmp_digit);
	ft_putstr(word);
}

/* Prints number classifier */
void	ft_classifiers(int n, char ***dict, int n_keys)
{
	int		i;
	char	tmp_digit[500];
	char	*word;

	i = 1;
	tmp_digit[0] = '1';
	while (i <= n)
	{
		tmp_digit[i] = '0';
		i++;
	}
	tmp_digit[i] = '\0';
	word = ft_find_word(dict, n_keys, tmp_digit);
	ft_putstr(word);
}
