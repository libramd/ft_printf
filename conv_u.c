/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:29:35 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/28 18:00:54 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nb_neg(va_list ap)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	if (nb < 0)
		return (4294967296 + nb);
	else
		return (nb);
}

static void	ft_aligned_left(unsigned int nb, int largeur, int precision,
		int *count)
{
	int	i;

	i = 0;
	if (precision == 0)
	{
		ft_putnbr(nb, count);
		while (i++ < (largeur - ft_intlen_unsigned(nb)))
			ft_putchar(' ', count);
	}
	else if (precision != 0)
	{
		i = 0;
		while (i++ < (precision - ft_intlen_unsigned(nb)))
			ft_putchar('0', count);
		ft_putnbr_unsigned(nb, count);
		i = 0;
		while (i++ < (largeur - precision))
			ft_putchar(' ', count);
	}
}

static void	ft_zero_len(unsigned int nb, int largeur, int precision,
		int *count)
{
	int	i;

	i = 0;
	if (precision == 0)
	{
		while (i++ < (largeur - ft_intlen_unsigned(nb)))
			ft_putchar('0', count);
	}
	else if (precision != 0)
	{
		while (i++ < (largeur - precision))
			ft_putchar(' ', count);
		i = 0;
		while (i++ < (precision - ft_intlen_unsigned(nb)))
			ft_putchar('0', count);
	}
	ft_putnbr_unsigned(nb, count);
}

static void	ft_aligned_right(unsigned int nb, int largeur,
		int precision, int *count)
{
	int	i;

	i = 0;
	if (precision == 0)
	{
		while (i++ < (largeur - ft_intlen_unsigned(nb)))
			ft_putchar(' ', count);
	}
	else if (precision != 0)
	{
		while (i++ < (largeur - precision))
			ft_putchar(' ', count);
		i = 0;
		while (i++ < (precision - ft_intlen_unsigned(nb)))
			ft_putchar('0', count);
	}
	ft_putnbr_unsigned(nb, count);
}

void	ft_conv_u(const char *str, va_list ap, int *count)
{
	char			*conv;
	t_bloc			s;
	unsigned int	nb;

	ft_poulet(&s, str, ap);
	nb = ft_nb_neg(ap);
	if (s.moins == 1)
		ft_aligned_left(nb, s.largeur, s.precision, count);
	else if (s.zero == 1)
		ft_zero_len(nb, s.largeur, s.precision, count);
	else if (s.zero == 0 && s.moins == 0)
		ft_aligned_right(nb, s.largeur, s.precision, count);
}
