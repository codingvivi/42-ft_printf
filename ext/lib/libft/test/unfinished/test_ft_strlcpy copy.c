/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ex01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:41:48 by lrain             #+#    #+#             */
/*   Updated: 2025/10/29 22:31:34 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_helpers.h"
#include "unity.h"
#include <string.h>

extern int	ft_strncmp(char *s1, char *s2, unsigned int n);

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_greater(void)
{
	// TEST_ASSERT_EQUAL_INT_MESSAGE(strncmp("the quick brown fox jumps over the lazy dog!",
	// 		"The quick brown fox jumps over the lazy dog!", 45),
	// 	ft_strncmp("the quick brown fox jumps over the lazy dog!",
	// 		"The quick brown fox jumps over the lazy dog!", 45),
	// 	"Divergent behavior from string.h!");
	TEST_ASSERT_EQUAL_INT('t' - 'T',
		ft_strncmp("the quick brown fox jumps over the lazy dog!",
			"The quick brown fox jumps over the lazy dog!", 44));
}

void	test_lesser(void)
{
	// TEST_ASSERT_EQUAL_INT_MESSAGE(strncmp("the quick brown fox jumps over the lazy dog!",
	// 		"The quick brown fox jumps over the lazy dog!", 44),
	// 	ft_strncmp("the quick brown fox jumps over the lazy dog!",
	// 		"The quick brown fox jumps over the lazy dog!", 44),
	// "Divergent behavior from string.h!");
	TEST_ASSERT_EQUAL_INT('T' - 't',
		ft_strncmp("The quick brown fox jumps over the lazy dog!",
			"the quick brown fox jumps over the lazy dog!", 44));
}

void	test_equal_strings_and_input(void)
{
	char	printables[203] = WHITESPACE ALL_PRINTABLE_ASCII WHITESPACE ALL_PRINTABLE_ASCII;

	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(LOWERCASE_LETTERS, LOWERCASE_LETTERS,
			26));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(UPPERCASE_LETTERS, UPPERCASE_LETTERS,
			26));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(DIGITS, DIGITS, 10));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(SPECIALS, SPECIALS, 35));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(printables, printables, 202));
}
void	test_empty_string(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("", "", 1));
}

void	test_n_0(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("", "", 0));
}
void	test_n_exit(void)
{
	TEST_ASSERT_EQUAL_INT(strncmp("123", "1234", 3), ft_strncmp("123", "1234",
			3));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("123", "1234", 3));
	TEST_ASSERT_NOT_EQUAL_INT(0, ft_strncmp("123", "1234", 4));
}
