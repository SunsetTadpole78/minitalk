/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:11:06 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/24 12:43:34 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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


int	send_char(int pid, int c)
{
	int	i;
	int	pong;

	i = 8;
	while (i != 0)
	{
		if ((c >> (i - 1)) & 1)
			pong = kill(pid, SIGUSR2);
		else
			pong = kill(pid, SIGUSR1);
		if (pong == -1)
			return (0);
		usleep(750);
		i--;
	}
	return (1);
}

int	send(int pid, char *message)
{
	int	i;

	i = 0;
	while (i == 0 || message[i - 1])
	{
		if (!send_char(pid, message[i]))
			return (0);
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{

	if (argc < 3 || argc > 3 || !is_digit(argv[1]))
	{
		ft_printf("Invalid format\n");
		return (1);
	}
	if (!send(ft_mini_atoi(argv[1]), argv[2]))
	{
		ft_printf("Invalid pid %s\n", argv[1]);
		return (2);
	}
	return (0);
}

