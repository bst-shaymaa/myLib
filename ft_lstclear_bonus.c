/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:35:16 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:11:22 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cel;

	if (!lst || !del)
		return ;
	while (*lst && lst)
	{
		cel = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cel;
	}
	lst = NULL;
}
