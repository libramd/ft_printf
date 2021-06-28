/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:36:42 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/28 18:14:48 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_xup(unsigned long long int n, char *base)
{
	char	*rev;
	char	*res;
	int		i;
	int		len;
	int		remain;

	i = 0;
	remain = 0;
	len = ft_strlen(base);
	rev = ft_calloc(sizeof(rev), 64);
	while (n > 0)
	{
		remain = n % len;
		if (remain < 10)
			rev[i] = remain + '0';
		else
			rev[i] = 'A' + (remain - 10);
		n = n / len;
		i++;
	}
	ft_rev_tab(rev);
	res = rev;
	free(rev);
	rev = NULL;
	return (res);
}

static void	ft_aligned_left(char *str, int largeur, int precision, int *count)
{
	int	i;

	i = 0;
	ft_putstr(str, count);
	while (i++ < (largeur - ft_strlen(str)))
		ft_putchar(' ', count);
}

static void	ft_aligned_right(char *str, int largeur, int precision, int *count)
{
	int	i;

	i = 0;
	while (i++ < (largeur - ft_strlen(str)))
		ft_putchar(' ', count);
	ft_putstr(str, count);
}

static char	*ft_getxup(va_list ap)
{
	int	nb;

	nb = va_arg(ap, int);
	return (ft_itoa_base_xup(nb, "0123456789ABCDEF"));
}

void	ft_conv_xup(const char *str, va_list ap, int *count)
{
	char	*conv;
	t_bloc	s;
	char	*str2;

	set_arg_zero(&s);
	conv = ft_copy_conv(str);
	set_arg(conv, &s, ap);
	free(conv);
	str2 = ft_getxup(ap);
	if (s.moins == 1)
		ft_aligned_left(str2, s.largeur, s.precision, count);
	else if (s.zero == 1)
		ft_aligned_right(str2, s.largeur, s.precision, count);
	else if (s.zero == 0 && s.moins == 0)
		ft_aligned_right(str2, s.largeur, s.precision, count);
}
