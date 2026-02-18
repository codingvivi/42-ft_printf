/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_strchr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:13:50 by lrain             #+#    #+#             */
/*   Updated: 2025/12/17 18:36:03 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <memory.h>
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
	// clean stuff up here
}

void test_asciis_unsigned(void)
{
	TEST_IGNORE();
	char          src[NUM_OF_ASCIIS];
	char         *target;
	char         *actual;
	unsigned char test_input;
	const int     last_ascii_index = NUM_OF_ASCIIS - 1;

	get_all_asciis(src);
	for (test_input = 1; test_input < last_ascii_index; test_input++)
	{
		target = strchr(src, test_input);
		actual = ft_strchr(src, test_input);
		check_against_stdlib(target, actual);
	}
	// check last character, would overflow otherwise
	strchr(src, test_input);
	ft_strchr(src, test_input);
	check_against_stdlib(target, actual);
}

void test_count_0(void)
{
	TEST_IGNORE();
	char          target[10] = {0};
	char          actual[10] = {0};
	unsigned char test_input;

	for (test_input = 127; test_input > 1; test_input--)
	{
		memset(target, test_input, 0);
		ft_memset(actual, test_input, 0);
	}
	memset(target, test_input, 0);
	ft_memset(actual, test_input, 0);
}
