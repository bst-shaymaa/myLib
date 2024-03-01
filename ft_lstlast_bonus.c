/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 08:11:11 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:11:44 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cel;

	cel = lst;
	if (!lst)
		return (NULL);
	while (cel)
	{
		if (cel->next == NULL)
			return (cel);
		cel = cel->next;
	}
	return (cel);
}
