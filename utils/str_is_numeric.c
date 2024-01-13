/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:44:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/13 20:28:50 by tunsal           ###   ########.fr       */
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

// int	main() {
// 	printf("str_is_numeric(%s) = %s\n", "-2147483650", str_is_numeric("-2147483650") ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "-2147483649", str_is_numeric("-2147483649") ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "-2147483648", str_is_numeric("-2147483648") ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "-2147483647", str_is_numeric("-2147483647") ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "-2147483645", str_is_numeric("-2147483645") ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "-214748",     str_is_numeric("-214748")     ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "0",           str_is_numeric("0")           ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "214748",      str_is_numeric("214748")      ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "2147483647",  str_is_numeric("2147483647")  ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "2147483648",  str_is_numeric("2147483648")  ? "true" : "false");
// 	printf("str_is_numeric(%s) = %s\n", "a",           str_is_numeric("a")           ? "true" : "false");
// }
