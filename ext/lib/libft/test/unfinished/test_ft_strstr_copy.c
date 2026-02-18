/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ex04.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:01:03 by lrain             #+#    #+#             */
/*   Updated: 2025/10/29 22:44:56 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_helpers.h"
#include "unity.h"
#include <string.h>

extern char	*ft_strstr(char *str, char *to_find);

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_all_asciis(void)
{
	char	*str_test;
	char	*to_find_test;

	str_test = ALL_PRINTABLE_ASCII WHITESPACE WHITESPACE ALL_PRINTABLE_ASCII;
	to_find_test = WHITESPACE ALL_PRINTABLE_ASCII;
	///// tests
	TEST_ASSERT_EQUAL_PTR(strstr(str_test, to_find_test), ft_strstr(str_test,
			to_find_test));
	TEST_ASSERT_EQUAL_STRING(to_find_test, ft_strstr(str_test, to_find_test));
	TEST_ASSERT_EQUAL_STRING(to_find_test, strstr(str_test, to_find_test));
	// // compare returned strings
	TEST_ASSERT_EQUAL_STRING(strstr(str_test, to_find_test), ft_strstr(str_test,
			to_find_test));
}

void	test_repeat_match(void)
{
	char	*str_test;
	char	*to_find_test;

	str_test = "12312";
	to_find_test = "12";
	///// tests
	TEST_ASSERT_EQUAL_PTR_MESSAGE(strstr(str_test, to_find_test),
		ft_strstr(str_test, to_find_test), "Different pointer from string.h!");
	// TEST_ASSERT_EQUAL_STRING(to_find_test, ft_strstr(str_test,
	// to_find_test));
	// TEST_ASSERT_EQUAL_STRING(to_find_test, strstr(str_test, to_find_test));
	// // compare returned strings
	TEST_ASSERT_EQUAL_STRING(strstr(str_test, to_find_test), ft_strstr(str_test,
			to_find_test));
}

void	test_empty_str(void)
{
	char	*str_test;
	char	*to_find_test;

	str_test = "";
	to_find_test = WHITESPACE ALL_PRINTABLE_ASCII;
	TEST_ASSERT_EQUAL_PTR(strstr(str_test, to_find_test), ft_strstr(str_test,
			to_find_test));
	// null pointers returned
	TEST_ASSERT_EQUAL_PTR(NULL, ft_strstr(str_test, to_find_test));
	TEST_ASSERT_EQUAL_PTR(NULL, strstr(str_test, to_find_test));
}

void	test_empty_to_find(void)
{
	char	*str_test;
	char	*to_find_test;

	str_test = "";
	to_find_test = "";
	TEST_ASSERT_EQUAL_PTR(strstr(str_test, to_find_test), ft_strstr(str_test,
			to_find_test));
	// returned strings are expected and the same
	TEST_ASSERT_EQUAL_STRING_MESSAGE(to_find_test, ft_strstr(str_test,
			to_find_test), "Expected != ft");
	TEST_ASSERT_EQUAL_STRING_MESSAGE(to_find_test, strstr(str_test,
			to_find_test), "Expected != std");
	TEST_ASSERT_EQUAL_STRING_MESSAGE(strstr(str_test, to_find_test),
		ft_strstr(str_test, to_find_test), "Divergent behavior from string.h!");
}

void	test_full_find(void)
{
	char	*str_test;
	char	*to_find_test;

	str_test = ALL_PRINTABLE_ASCII;
	to_find_test = ALL_PRINTABLE_ASCII;
	TEST_ASSERT_EQUAL_PTR(strstr(str_test, to_find_test), ft_strstr(str_test,
			to_find_test));
	// returned strings are expected and the same
	TEST_ASSERT_EQUAL_STRING(to_find_test, ft_strstr(str_test, to_find_test));
	TEST_ASSERT_EQUAL_STRING(to_find_test, strstr(str_test, to_find_test));
	TEST_ASSERT_EQUAL_STRING(strstr(str_test, to_find_test), ft_strstr(str_test,
			to_find_test));
}
