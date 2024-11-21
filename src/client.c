/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:11:06 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/21 17:25:35 by lroussel         ###   ########.fr       */
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

void	send(int pid, char *str)
{
	sigset_t	set;

	ft_printf("%i | %s\n\n", pid, str);
	sigemptyset(&set);
}

int	main(int argc, char **argv)
{
	if (argc < 3 || argc > 3 || !is_digit(argv[1]))
	{
		ft_printf("Invalid format\n");//TODO
		return (1);
	}
	if (kill(ft_mini_atoi(argv[1]), SIGUSR1) == -1)
	{
		ft_printf("Invalid pid %s", argv[1]);
		return (2);
	}
	send(ft_mini_atoi(argv[1]), argv[2]);
	//ft_printf("%s : %s", argv[1], argv[2]);
	return (0);
}
