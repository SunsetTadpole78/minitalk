/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:11:40 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/02 14:32:33 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	received;

void	wrong_pid(int pid)
{
	ft_printf("Invalid PID: %i\n", pid);//TODO
	exit(EXIT_FAILURE);
}

void	send_sig(int pid, int sig)
{
	int	fail;

	received = 0;
	if (kill(pid, sig) == -1)
		wrong_pid(pid);

	fail = 0;
	while (!received)
	{
		usleep(5);
		if (fail > 50)
		{
			send_sig(pid, sig);
			break ;
		}
		fail++;
	}
}

void	send_char(int pid, int c)
{	
	int	i;

	i = 8;
	while (i-- != 0)
		send_sig(pid, 10 + ((c >> i) & 1) * 2);
}

void	send_signature(int pid, int len, int start)
{
	signal(SIGUSR1, sresend);
	if (len <= 0)
		return ;
	send_signature(pid, len / 10, 0);
	send_char(pid, (len % 10) + '0');
	if (start)
		send_char(pid, 'a');
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	signal(SIGUSR1, sresend);
	while (i == 0 || message[i - 1])
	{
		if (resend(0))
			return ;
		send_char(pid, message[i]);
		i++;
	}
}

void	send(int pid, char *message)
{
	resend(2);
	send_signature(pid, ft_strlen(message), 1);
	if (resend(0))
	{
		send(pid, message);
		return ;
	}
	resend(2);
	send_message(pid, message);
	if (resend(0))
	{
		send(pid, message);
		return ;
	}
}

void	on_receive(int sig)
{
	(void)sig;
	received = 1;
}

int	main(int argc, char **argv)
{

	if (argc != 3 || !is_digit(argv[1]))
	{
		ft_printf("invalid format\n");//TODO
		return (1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_printf("empty message\n");//TODO
		return (2);
	}
	signal(SIGUSR2, on_receive);
	send(ft_mini_atoi(argv[1]), argv[2]);
}
