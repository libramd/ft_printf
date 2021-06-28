/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:11 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/28 16:48:33 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nb, int *count)
{
	unsigned int	x;

	x = nb;
	if (x < 0)
	{
		x = x * -1;
		ft_putchar('-', count);
	}
	if (x > 9)
	{
		ft_putnbr_unsigned(x / 10, count);
		ft_putnbr_unsigned(x % 10, count);
	}
	else
	{
		ft_putchar(x + '0', count);
	}
}

int	ft_intlen_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_zin(unsigned int nb)
{
	int	res;

	res = ft_intlen_unsigned(nb);
	return (res);
}

void	ft_rev_tab(char *tab)
{
	char	tmp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(tab) - 1;
	while (start <= end)
	{
		tmp = tab[start];
		tab[start] = tab[end];
		tab[end] = tmp;
		start++;
		end--;
	}
}

char	*ft_itoa_base(unsigned long long int n, char *base)
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
			rev[i] = 'a' + (remain - 10);
		n = n / len;
		i++;
	}
	ft_rev_tab(rev);
	res = rev;
	ft_free_str(rev);
	return (res);
}

/*int	main()
{
	int	g;
	char	*t;

	g = 458204;
	t = ft_itoa_base(g, "0123456789abcdef");
	printf("%s\n", t);
}*/
