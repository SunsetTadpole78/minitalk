/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:56:05 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 16:57:40 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error(char *message, int format, int br)
{
	int	i;

	write(2, "\033[41m[Error] ", 13 - 8 * (!format));
	i = 0;
	while (message[i])
		i++;
	write(2, message, i);
	write(2, "\033[49m", 5);
	if (br)
		write(2, "\n", 1);
}

void	wrong_pid(void)
{
	error("Invalid PID", 1, 1);
	exit(EXIT_FAILURE);
}

void	invalid_format(char *name, char *format)
{
	error("Usage: ", 1, 0);
	error(name, 0, 0);
	error(" ", 0, 0);
	error(format, 0, 1);
	exit(EXIT_FAILURE);
}

void	empty_message(void)
{
	error("Empty Message", 1, 1);
	exit(EXIT_FAILURE);
}

void	fail_malloc(void)
{
	error("Malloc fail", 1, 1);
	exit(EXIT_FAILURE);
}

void	warning(char *message)
{
	ft_printf("\033[38;5;208m[Warning] %s\033[0m\n", message);
}
