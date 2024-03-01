/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:16:44 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:13:59 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		length;
	char	*str;

	i = 0;
	length = 0;
	while (s[length])
		length++;
	str = malloc(sizeof(*str) * (length + 1));
	if (!str) 
		return (NULL);
	if (str != NULL)
	{
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
