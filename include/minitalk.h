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

//utils.c
void	char_repeat(char c, int times, int linebreak);
void	ft_bzero(char *message, int len);
int		is_digit(char *str);
void	warning(char *message);

//error.c
void	empty_message(void);
void	fail_malloc(void);
void	invalid_format(char *name, char *format);
void	wrong_pid(void);

#endif
