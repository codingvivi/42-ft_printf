/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04/ft_strstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:58:40 by lrain             #+#    #+#             */
/*   Updated: 2025/10/26 12:04:04 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	is_match(char *s1, char *s2);

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	else
	{
		while (*str != '\0')
		{
			if (is_match(str, to_find) == true)
				return (str);
			str++;
		}
		return (NULL);
	}
}

bool	is_match(char *str, char *to_find)
{
	while (*str != '\0' && *to_find != '\0' && *str == *to_find)
	{
		str++;
		to_find++;
	}
	if (*to_find == '\0')
		return (true);
	else
		return (false);
}
