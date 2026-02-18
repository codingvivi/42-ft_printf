/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_isascii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:22:06 by lrain             #+#    #+#             */
/*   Updated: 2025/12/12 17:17:32 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <ctype.h>
#include <stdbool.h>

void	setUp(void)
{
	// set stuff up here
}

void	tearDown(void)
{
	// clean stuff up here
}

void	check_against_ctype(int test_input)
{
	bool	libc_result;
	bool	ft_result;

	libc_result = isascii(test_input);
	ft_result = ft_isascii(test_input);
	TEST_ASSERT(libc_result == ft_result);
	VERBOSE_PRINT("✓ check ok! target: %d, actual: %d", libc_result, ft_result);
}

void	test_asciis_unsigned(void)
{
	unsigned char	test_input;

	for (test_input = 0; test_input < 127; test_input++)
		check_against_ctype(test_input);
	check_against_ctype(test_input);
}

void	test_asciis_signed(void)
{
	for (signed char test_input = 0; test_input < 127; test_input++)
		check_against_ctype(test_input);
}

void	test_int_signed(void)
{
	for (int test_input = -1000; test_input <= 1000; test_input++)
		check_against_ctype(test_input);
}
