/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 08:01:25 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:11:58 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*cel;

	if (!lst)
		return (0);
	count = 0;
	cel = lst;
	while (cel)
	{
		cel = cel->next;
		count++;
	}
	return (count);
}
