/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:44:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/15 16:55:20 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	char_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

/* Return whether string only consists of digits or not. */
int	str_is_numeric(char *s)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	if (s == NULL || len < 1)
		return (0);
	if (s[0] == '-')
	{
		if (len == 1)
			return (0);
	}
	else if (!char_is_numeric(s[0]))
		return (0);
	i = 1;
	while (s[i] != '\0')
	{
		if (!char_is_numeric(s[i]))
			return (0);
		++i;
	}
	return (1);
}
