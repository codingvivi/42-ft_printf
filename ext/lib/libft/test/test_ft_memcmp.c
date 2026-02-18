/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_memcmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:09:39 by lrain             #+#    #+#             */
/*   Updated: 2025/12/20 11:23:56 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <stdio.h>
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_greater(void)
{
	const char *lhs = "the quick brown fox jumps over the lazy dog!";
	const char *rhs = "The quick brown fox jumps over the lazy dog!";
	const int   target_ret = memcmp(lhs, rhs, 45);
	const int   actual_ret = ft_memcmp(lhs, rhs, 45);

	printf("target: %d, actual %d", target_ret, actual_ret);
	// TEST_ASSERT(target_ret == actual_ret);
}

void test_lesser(void)
{
	const char *lhs = "The quick brown fox jumps over the lazy dog!";
	const char *rhs = "the quick brown fox jumps over the lazy dog!";
	const int   target_ret = memcmp(lhs, rhs, 45);
	const int   actual_ret = ft_memcmp(lhs, rhs, 45);

	TEST_ASSERT(target_ret == actual_ret);
}

void test_equal_strings_and_input(void)
{
	char printables[203] = WHITESPACE ALL_PRINTABLE_ASCII WHITESPACE ALL_PRINTABLE_ASCII;

	TEST_ASSERT_EQUAL_INT(0, ft_memcmp(LOWERCASE_LETTERS, LOWERCASE_LETTERS, 26));
	TEST_ASSERT_EQUAL_INT(0, ft_memcmp(UPPERCASE_LETTERS, UPPERCASE_LETTERS, 26));
	TEST_ASSERT_EQUAL_INT(0, ft_memcmp(DIGITS, DIGITS, 10));
	TEST_ASSERT_EQUAL_INT(0, ft_memcmp(SPECIALS, SPECIALS, 35));
	TEST_ASSERT_EQUAL_INT(0, ft_memcmp(printables, printables, 202));
}

void test_empty_string(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_memcmp("", "", 1));
}

void test_n_0(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_memcmp("", "", 0));
}

void test_n_exit(void)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(memcmp("123", "1234", 3), ft_memcmp("123", "1234", 3), "Diverges from stdlib");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ft_memcmp("123", "1234", 3), "Expected result different for count 3");
	TEST_ASSERT_NOT_EQUAL_INT_MESSAGE(0, ft_memcmp("123", "1234", 4), "Expected result different for count 4");
}
