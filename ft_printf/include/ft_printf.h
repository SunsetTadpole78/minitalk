/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:04:23 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 21:31:51 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/* _______________________________ Structure ________________________________ */

typedef struct s_data
{
	int		size;
	char	type;
	int		minus;
	int		zero;
	int		dot;
	int		hashtag;
	int		space;
	int		plus;
	int		padding;
	int		elsize;
}	t_data;

/* ___________________________ data_initializer.c ___________________________ */

t_data			init_data(const char *format, va_list args);
void			init_flags(t_data *data);
void			update_flags(const char *c, t_data *data, va_list args);
void			update_values(t_data *data);

/* __________________________ default_formatter.c ___________________________ */

int				format_char(t_data data, char c);
int				format_str(t_data data, char *str);
int				format_int(t_data data, long int nbr);
int				format_unsigned_int(t_data data, unsigned int nbr);

/* ______________________________ ft_printf.c _______________________________ */

int				ft_printf(const char *format, ...);
t_data			format_switcher(const char *format, va_list args, int *printed);

/* ___________________________ hbase_formatter.c ____________________________ */

int				format_hexa(t_data data, unsigned long nbr);
int				format_pointer(t_data data, void *p);

/* _______________________________ len_utils.c ______________________________ */

int				ft_strlen(char *str);
unsigned int	ft_log(int long nb, int len);
int				ft_hexalen(unsigned long nbr);
int				ft_pointerlen(void *p);

/* ______________________________ lib_utils.c _______________________________ */

char			*ft_strchr(const char *s, int c);
long int		ft_abs(long int nbr);
int				ft_mini_atoi(const char *nptr);

/* ___________________________ values_printers.c ____________________________ */

int				ft_print_char(char c, int times);
int				ft_print_str(char *str, int size);
int				ft_print_unsigned_int(unsigned int nbr);
int				ft_print_hexa(unsigned long value, char type);
int				ft_print_pointer(void *p);

#endif
