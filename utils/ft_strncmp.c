/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:50:39 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:50:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Similar to strcmp(), except it compares first `cmp_lim` bytes at most. */
int	ft_strncmp(char *s1, char *s2, size_t cmp_lim)
{
	size_t			i;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *) s1;
	u2 = (unsigned char *) s2;
	i = 0;
	while (i < cmp_lim)
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		if (u1[i] == '\0')
			return (0);
		++i;
	}
	return (0);
}
