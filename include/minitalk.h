/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:46:45 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/02 11:38:04 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "ft_printf.h"
# include <signal.h>
# include <stdlib.h>

int	is_digit(char *str);
int	resend(int type);
void	sresend(int sig);

#endif
