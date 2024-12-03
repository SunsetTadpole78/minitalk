/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:11:40 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/02 16:59:53 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received;

void	set_received(int received)
{
	g_received = received;
}

int	is_received(void)
{
	return (g_received);
}

void	on_receive(int sig)
{
	(void)sig;
	g_received = 1;
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !is_digit(argv[1]))
		invalid_format(argv[0], "<pid> <message>");
	if (ft_strlen(argv[2]) == 0)
		empty_message();
	signal(SIGUSR2, on_receive);
	send(ft_mini_atoi(argv[1]), argv[2]);
}
