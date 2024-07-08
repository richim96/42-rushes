/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:09:47 by rmei              #+#    #+#             */
/*   Updated: 2024/02/18 22:54:56 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_is_args_valid(int argc, char **argv, char **dict, char *num);
void	ft_putstr(char *str);
char	*ft_strcpy(char *dest, char *src);
