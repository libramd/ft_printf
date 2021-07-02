/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:36:14 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/07/02 15:38:15 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

typedef struct	s_bloc
{
	int		moins;
	int		zero;
	int		etoile_largeur;
	int		etoile_precision;
	int		largeur;
	int		precision;
}				t_bloc;

int				ft_strlen_b(const char *str, int precision);
void			ft_poulet(t_bloc *s, const char *str, va_list ap);
void			ft_free_str(char *str);
void			*ft_memset(void *pointer, int value, size_t size);
void			*ft_calloc(size_t count, size_t size);
void			ft_rev_tab(char *tab);
char    		*ft_itoa_base_xup(unsigned long long int n, char *base);
void			ft_conv_xup(const char *str, va_list ap, int *count);
void			ft_conv_x(const char *str, va_list ap, int *count);
char			*ft_getx(va_list ap);
char    		*ft_itoa_base(unsigned long long int n, char *base);
void			ft_conv_p(const char *str, va_list ap, int *count);
char			*ft_getp(va_list ap);
int				ft_zin(unsigned int nb);
int				ft_intlen_unsigned(unsigned int nb);
void			ft_putnbr_unsigned(unsigned int nb, int *count);
void			ft_conv_u(const char *str, va_list ap, int *count);
unsigned int	ft_nb_neg(va_list ap);
void			ft_conv_s(const char *str, va_list ap, int *count);
void			ft_conv_c(const char *str, va_list ap, int *count);
void			ft_carrefour(const char *str, va_list ap, int *count);
char			ft_defconv(const char *str);
void			ft_conv_d(const char	*str, va_list ap2, int *count);
int				ft_strchr(char *set, char c);
int				ft_atoi(char *str);
int 			ft_isconv(char c);
char			*ft_copy_conv(const char *str);
int				ft_len_digit(char *str);
int				ft_len_conv(const char *str);
int				ft_isdigit(char c);
int				ft_is_letter(char c);
int				ft_intlen(int nb);
void			set_arg(char *str, t_bloc *s, va_list ap);
void			set_larg_prec(va_list ap, char *str, t_bloc *s);
void			set_arg_zero(t_bloc *s);
int				ft_printf(const char *str, ...);
int				ft_strlen(const char *str);
void			ft_putchar(char c, int *count);
void			ft_putstr(const char *str, int *count);
void			ft_putnbr(int nb, int *count);

#endif
