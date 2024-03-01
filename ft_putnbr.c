/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:25:19 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:13:26 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

static int	ft_nbrlen(long n)
{
	int	i;

	if (n < 0)
	{
		n = n * (-1);
		i = 1;
	}
	else
		i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static void	ft_putbase(int nbr, const char *base)
{
	int		base_len;
	long	nb;
	char	c;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = -((long)nbr);
	}
	else
		nb = (long)nbr;
	if (nb > (base_len - 1))
		ft_putbase(nb / base_len, base);
	c = *(base + (nb % base_len));
	write(1, &c, 1);
}

int	ft_putnbr(int n)
{
	char const	*base;
	int			nbr_len;

	nbr_len = ft_nbrlen(n);
	base = "0123456789";
	ft_putbase(n, base);
	return (nbr_len);
}
