/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:44:17 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/24 17:39:49 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return whether string only consists of digits or not. */
int	str_is_numeric(char *s)
{
	size_t	i;
	int		encountered_a_num;
	int		encountered_sign;

	if (s == NULL || ft_strlen(s) < 1)
		return (0);
	encountered_a_num = 0;
	encountered_sign = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '-' && (s[i] < '0' || s[i] > '9'))
			return (0);
		if (s[i] >= '0' && s[i] <= '9')
			encountered_a_num = 1;
		if (s[i] == '-')
			encountered_sign = 1;
		if ((encountered_a_num || encountered_sign) && s[i] == '-')
			return (0);
		++i;
	}
	if (!encountered_a_num)
		return (0);
	return (1);
}
