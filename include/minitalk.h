/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:46:45 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 16:12:20 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "ft_printf.h"
# include <signal.h>
# include <stdlib.h>

int		is_digit(char *str);
int		resend(int type);
void	sresend(int sig);
void	ft_bzero(char *element, int len);

void	wrong_pid(void);
void	invalid_format(char *name, char *format);
void	empty_message(void);
void	fail_malloc(void);
void	warning(char *message);

void	process_signature(int sig, int *len);
void	process(int sig, siginfo_t *info, void *context);

void	send_sig(int pid, int sig);
void	send_char(int pid, int c);
void	send_signature(int pid, int len, int start);
void	send_message(int pid, char *message);
void	send(int pid, char *message);

void	set_received(int received);
int		is_received(void);

void	set_type(int type);
int		get_type(void);

void	head(void);

char	*process_element(int len, char c, int type);

#endif
