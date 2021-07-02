/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:32:11 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/07/02 15:38:12 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_b(const char *str, int precision, int *count)
{
	int	i;

	i = 0;
	if (precision != -1)
	{
		if (str)
		{
			while (str[i] && i < precision)
			{
				ft_putchar(str[i], count);
				i++;
			}
		}
	}
	else
		ft_putstr(str, count);
}

static void    ft_aligned_left(const char *str, int largeur, int precision, int *count)
{
    int    i;

    i = 0;
	ft_putstr_b(str, precision, count);
	while (i < (largeur - ft_strlen_b(str, precision)))
	{
            ft_putchar(' ', count);
			i++;
	}
}

static void    ft_zero_len(const char *str, int largeur, int precision, int *count)
{
    int    i;

    i = 0;
	while (i < (largeur - ft_strlen_b(str, precision)))
	{
		ft_putchar('0', count);
		i++;
	}
	ft_putstr_b(str, precision, count);
}

static void    ft_aligned_right(const char *str, int largeur, int precision, int *count)
{
    int    i;

    i = 0;
	while (i < (largeur - ft_strlen_b(str, precision)))
	{
		ft_putchar(' ', count);
		i++;
	}
	ft_putstr_b(str, precision, count);
}

void	ft_conv_s(const char *str, va_list ap, int *count)
{
	char	*conv;
	t_bloc	s;
	char	*str2;

	set_arg_zero(&s);
	conv = ft_copy_conv(str);
	set_arg(conv, &s, ap);
	free(conv);
	str2 = va_arg(ap, char *);
	if (s.moins == 1)
		ft_aligned_left(str2, s.largeur, s.precision, count);
	else if (s.zero == 1)
		ft_zero_len(str2, s.largeur, s.precision, count);
	else if (s.zero == 0 && s.moins == 0)
		ft_aligned_right(str2, s.largeur, s.precision, count);
}
