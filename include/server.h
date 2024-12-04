/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:55:04 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/04 10:14:42 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

//header.c
void	header(void);

//message_utils.c
void	print_message(char *word, int len);
char	*process_message(int len, char c, int type);

//receiver.c
void	process(int sig, siginfo_t *info, void *context);

//signature_utils.c
int		check_signature(int sig, siginfo_t *info, int *len);

//type_utils.c
int		get_type(void);
void	set_type(int type);

#endif
