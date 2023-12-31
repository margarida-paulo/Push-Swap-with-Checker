/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:26:22 by maggie            #+#    #+#             */
/*   Updated: 2023/09/05 14:24:19 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_top(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	if (cheapest->action == UPUP)
		ft_rtop(head_a, head_b, cheapest);
	else if (cheapest->action == DOWNDOWN)
		ft_rrtop(head_a, head_b, cheapest);
	else if (cheapest->action == UPDOWN)
		ft_updown(head_a, head_b, cheapest);
	else
		ft_downup(head_a, head_b, cheapest);
}

void	ft_downup(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	size_t	downcost_a;
	size_t	upcost_b;

	downcost_a = cheapest->tar->down_cost;
	upcost_b = cheapest->up_cost;
	while (downcost_a-- > 0)
		ft_rra(head_a);
	while (upcost_b-- > 0)
		ft_rb(head_b);
}

int	ft_equal(char **str1, const char str2[])
{
	size_t	i;

	i = 0;
	while ((*str1)[i] && str2[i])
	{
		if ((*str1)[i] != str2[i])
			return (0);
		i++;
	}
	if ((*str1)[i] && !str2[i])
		return (0);
	if (str2[i] && !((*str1)[i]))
		return (0);
	return (1);
}
