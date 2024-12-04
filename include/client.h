/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:54:57 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/04 10:14:08 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

//acknowledgment_utils.c
void	handle_acknowledgment(int sig);
int		is_received(void);
void	set_received(int received);

//resend_utils.c
void	handle_resend(int sig);
int		resend(int type);

//sender.c
void	send(int pid, char *message);

#endif
