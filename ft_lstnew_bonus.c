/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:12:00 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:11:54 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cel;

	cel = (struct s_list *)malloc(sizeof(struct s_list));
	if (!cel)
		return (NULL);
	cel->content = content;
	cel->next = NULL;
	return (cel);
}
