/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_memset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:09:02 by lrain             #+#    #+#             */
/*   Updated: 2025/12/15 18:10:57 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>

#define ASCIISLEN 128

void	setUp(void)
{
}

void	tearDown(void)
{
	// clean stuff up here
}

void	test_asciis_unsigned(void)
{
	char			target[10] = {0};
	char			actual[10] = {0};
	unsigned char	test_input;

	for (test_input = 127; test_input >= 1; test_input--)
	{
		memset(target, test_input, 10);
		ft_memset(actual, test_input, 10);
	}
	printf("exited loop");
	memset(target, test_input, 10);
	ft_memset(actual, test_input, 10);
}

void	test_count_0(void)
{
	char			target[10] = {0};
	char			actual[10] = {0};
	unsigned char	test_input;

	for (test_input = 127; test_input >= 1; test_input--)
	{
		memset(target, test_input, 0);
		ft_memset(actual, test_input, 0);
	}
	memset(target, test_input, 0);
	ft_memset(actual, test_input, 0);
}
