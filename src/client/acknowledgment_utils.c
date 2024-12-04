/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acknowledgment_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:44:48 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/04 09:44:52 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"

int	g_received;

void	handle_acknowledgment(int sig)
{
	(void)sig;
	g_received = 1;
}

int	is_received(void)
{
	return (g_received);
}

void	set_received(int received)
{
	g_received = received;
}
