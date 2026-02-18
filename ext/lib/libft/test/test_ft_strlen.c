/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_strlen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:22:52 by lrain             #+#    #+#             */
/*   Updated: 2025/12/12 17:12:39 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <string.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

static void	is_expected_length(char *str, int expected_length);
static void	is_same_as_std_strlen(char *str);

void	test_write_uppercase(void)
{
	char	*test_str;

	test_str = UPPERCASE_LETTERS;
	is_expected_length(test_str, 26);
	is_same_as_std_strlen(test_str);
}

void	test_write_lowercase(void)
{
	char	*test_str;

	test_str = LOWERCASE_LETTERS;
	is_expected_length(test_str, 26);
	is_same_as_std_strlen(test_str);
}

void	test_write_numbers(void)
{
	char	*test_str;

	test_str = DIGITS;
	is_expected_length(test_str, 10);
	is_same_as_std_strlen(test_str);
}

void	test_write_specials(void)
{
	char	*test_str;

	test_str = SPECIALS;
	is_expected_length(test_str, 32);
	is_same_as_std_strlen(test_str);
}

void	test_write_whitespace(void)
{
	char	*test_str;

	test_str = WHITESPACE;
	is_expected_length(test_str, 6);
	is_same_as_std_strlen(test_str);
}

void	test_write_all_printables(void)
{
	char	*test_str;

	test_str = WHITESPACE ALL_PRINTABLE_ASCII WHITESPACE ALL_PRINTABLE_ASCII;
	is_expected_length(test_str, 202);
	is_same_as_std_strlen(test_str);
}

void	test_write_empty_string(void)
{
	char	*test_str;

	test_str = "";
	is_expected_length(test_str, 0);
	is_same_as_std_strlen(test_str);
}

// helper functions
void	is_expected_length(char *str, int expected_length)
{
	size_t	returned_length;

	returned_length = ft_strlen(str);
	TEST_ASSERT_EQUAL_INT(expected_length, returned_length);
}

static void	is_same_as_std_strlen(char *str)
{
	TEST_ASSERT_EQUAL_INT(strlen(str), ft_strlen(str));
}
