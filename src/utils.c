/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:15:29 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 18:36:34 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_repeat(char c, int times, int linebreak)
{
	int	i;

	i = 0;
	while (i < times)
	{
		ft_printf("%c", c);
		i++;
	}
	if (linebreak)
		ft_printf("\n");
}

void	ft_bzero(char *message, int len)
{
	while (len >= 0)
	{
		message[len] = '\0';
		len--;
	}
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	warning(char *message)
{
	ft_printf("\033[38;5;208m[Warning] %s\033[0m\n", message);
}
