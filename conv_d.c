/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:51:06 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/28 17:10:36 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aligned_left(int nb, int largeur, int precision,
		int *count)
{
	int	i;

	i = 0;
	if (precision == 0)
	{
		ft_putnbr(nb, count);
		while (i++ < (largeur - ft_intlen(nb)))
			ft_putchar(' ', count);
	}
	else if (precision != 0)
	{
		i = 0;
		while (i++ < (precision - ft_intlen(nb)))
			ft_putchar('0', count);
		ft_putnbr(nb, count);
		i = 0;
		while (i++ < (largeur - precision))
			ft_putchar(' ', count);
	}
}

static void	ft_zero_len(int nb, int largeur, int precision,
		int *count)
{
	int	i;

	i = 0;
	if (precision == 0)
	{
		while (i++ < (largeur - ft_intlen(nb)))
			ft_putchar('0', count);
	}
	else if (precision != 0)
	{
		while (i++ < (largeur - precision))
			ft_putchar(' ', count);
		i = 0;
		while (i++ < (precision - ft_intlen(nb)))
			ft_putchar('0', count);
	}
	ft_putnbr(nb, count);
}

static void	ft_aligned_right(int nb, int largeur, int precision,
		int *count)
{
	int	i;

	i = 0;
	if (precision == 0)
	{
		while (i++ < (largeur - ft_intlen(nb)))
			ft_putchar(' ', count);
	}
	else if (precision != 0)
	{
		while (i++ < (largeur - precision))
			ft_putchar(' ', count);
		i = 0;
		while (i++ < (precision - ft_intlen(nb)))
			ft_putchar('0', count);
	}
	ft_putnbr(nb, count);
}

void	ft_conv_d(const char *str, va_list ap, int *count)
{
	char	*conv;
	t_bloc	s;

	set_arg_zero(&s);
	conv = ft_copy_conv(str);
	set_arg(conv, &s, ap);
	free(conv);
	if (s.moins == 1)
		ft_aligned_left(va_arg(ap, int), s.largeur, s.precision, count);
	else if (s.zero == 1)
		ft_zero_len(va_arg(ap, int), s.largeur, s.precision, count);
	else if (s.zero == 0 && s.moins == 0)
		ft_aligned_right(va_arg(ap, int), s.largeur, s.precision, count);
}
