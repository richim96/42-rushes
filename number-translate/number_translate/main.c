/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:52:53 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 22:53:04 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	main(int argc, char **argv)
{
	char	**string_dict;
	char	*string_number;

	string_dict = "numbers.dict";
	if (!ft_is_args_valid(argc, argv, string_dict, string_number))
		return (1);
	
}
