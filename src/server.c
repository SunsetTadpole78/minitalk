/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:10:58 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/21 17:28:12 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	printheader(void)
{
	ft_printf("=========================================================================\n");
	ft_printf("|  ___  __ _       _ _        _ _    ");
	ft_printf("  _____                            |\n");
	ft_printf("|  |  \\/  (_)     (_) |      | | |  ");
	ft_printf("  /  ___|                           |\n");
	ft_printf("|  | .  . |_ _ __  _| |_ __ _| | | __ ");
	ft_printf("\\ `--.  ___ _ ____   _____ _ __   |\n");
	ft_printf("|  | |\\/| | | '_ \\| | __/ _` | | |/ ");
	ft_printf("/  `--. \\/ _ \\ '__\\ \\ / / _ \\ '__|  |\n");
	ft_printf("|  | |  | | | | | | | || (_| | |   <  ");
	ft_printf("/\\__/ /  __/ |   \\ V /  __/ |     |\n");
	ft_printf("|  \\_|  |_/_|_| |_|_|\\__\\__,_|_|_|\\");
	ft_printf("_\\ \\____/ \\___|_|    \\_/ \\___|_|     |\n");
	ft_printf("|                                                                       |\n");
	ft_printf("=============================== PID: %i ===============================", getpid());
	ft_printf("\n\n");
}

void	test(int num)
{
	ft_printf("Vous avez recu une notification, maintenant il faut la lire... (%i)\n", num);
}

int	main(void)
{
	printheader();
	while (1)
	{
		signal(SIGUSR1, test);
		usleep(100000);
	}
	return (0);
}
