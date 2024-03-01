/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:09:50 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:11:08 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

static size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		digit;
	long int	num;

	num = n;
	digit = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digit++;
	}
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	*(str + digit) = 0;
	while (digit--)
	{
		*(str + digit) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
