/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:19:14 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/28 18:01:59 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getx(va_list ap)
{
	int	nb;

	nb = va_arg(ap, int);
	return (ft_itoa_base(nb, "0123456789abcdef"));
}

static void	ft_aligned_left(char *str, int largeur, int precision,
		int *count)
{
	int	i;

	i = 0;
	ft_putstr(str, count);
	while (i++ < (largeur - ft_strlen(str)))
		ft_putchar(' ', count);
}

static void	ft_aligned_right(char *str, int largeur, int precision,
		int *count)
{
	int	i;

	i = 0;
	while (i++ < (largeur - ft_strlen(str)))
		ft_putchar(' ', count);
	ft_putstr(str, count);
}

void	ft_conv_x(const char *str, va_list ap, int *count)
{
	char	*conv;
	t_bloc	s;

	set_arg_zero(&s);
	conv = ft_copy_conv(str);
	set_arg(conv, &s, ap);
	free(conv);
	if (s.moins == 1)
		ft_aligned_left(ft_getx(ap), s.largeur, s.precision, count);
	else if (s.zero == 1)
		ft_aligned_right(ft_getx(ap), s.largeur, s.precision, count);
	else if (s.zero == 0 && s.moins == 0)
		ft_aligned_right(ft_getx(ap), s.largeur, s.precision, count);
}
