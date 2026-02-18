/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_strlcat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2027/10/24 22:01:03 by lrain             #+#    #+#             */
/*   Updated: 2025/12/20 11:25:19 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <string.h>

// #include <string.h>

static char dest_ft[27];
static char dest_control[27];

void init_array(char *dest);

void setUp(void)
{
	init_array(dest_ft);
	init_array(dest_control);
}

void init_array(char *dest)
{
	memset(dest, 'A', 27); // remove old \0
	dest[0] = '\0';
	// dest[27] = '\0';
}

void test_all_asciis(void)
{
	char dest_ft[203] = WHITESPACE ALL_PRINTABLE_ASCII;
	char dest_control[203] = WHITESPACE ALL_PRINTABLE_ASCII;
	char src_test[102] = WHITESPACE ALL_PRINTABLE_ASCII;
	char ref_hand_cat[203] = WHITESPACE ALL_PRINTABLE_ASCII WHITESPACE ALL_PRINTABLE_ASCII;

	TEST_ASSERT_EQUAL_INT(strlcat(dest_control, src_test, 203), ft_strlcat(dest_ft, src_test, 203));
	TEST_ASSERT_EQUAL_STRING_MESSAGE(dest_control, dest_ft, "Diverging behavior to bsd strlcat");
	TEST_ASSERT_EQUAL_STRING_MESSAGE(ref_hand_cat, dest_ft, "Failed on test hand");
	TEST_ASSERT_EQUAL_STRING_MESSAGE(ref_hand_cat, dest_control, "Failed on control");
}

static void concat_test(char *src, unsigned int size, char *expected_str, unsigned int expected_return)
{
	const unsigned int return_ft = ft_strlcat(dest_ft, src, size);
	const unsigned int return_control = strlcat(dest_control, src, size);

	// test return values
	TEST_ASSERT_EQUAL_UINT_MESSAGE(return_control, return_ft, "Diverging behavior from bsd lib");
	TEST_ASSERT_EQUAL_UINT_MESSAGE(expected_return, return_ft, "Diverging value from hand control");
	// test if resulting string is same
	TEST_ASSERT_EQUAL_STRING_MESSAGE(dest_control, dest_ft, "Diverging behavior from bsd lib");
	// double check if expected string is correct
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected_str, dest_ft, "Diverging value from hand control");
	// Check that the null terminator is at the right position
}

void test_empty_dest(void)
{
	char               src_test[6] = "Hello";
	char               expc_str[6] = "Hello";
	const unsigned int expc_ret = 5;

	concat_test(src_test, 27, expc_str, expc_ret);
}

void test_empty_src(void)
{
	char               src_test[1] = "";
	char               expc_str[1] = "";
	const unsigned int expc_ret = 0;

	concat_test(src_test, 27, expc_str, expc_ret);
}

void test_null_term_str_exit(void)
{
	char               src_test[33] = "Hello world!\0 DONT WRITE THIS THO";
	char               expc_str[13] = "Hello world!";
	const unsigned int expc_ret = 12;

	// init vars
	concat_test(src_test, 27, expc_str, expc_ret);
}

void test_size_exit(void)
{
	char src_test[53] = "Print 26 chars up 2 here!!< (and ignore the rest tbh)";
	char expc_str[27] = "Print 26 chars up 2 here!!";
	const unsigned int expc_ret = 54;

	// test
	concat_test(src_test, 27, expc_str, expc_ret);
}

void test_null_term_protect_exit(void)
{
	char src_test[42] = "42 chars long...null terminator included!!";
	char expc_str[27] = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
	const unsigned int expc_ret = 69;

	TEST_IGNORE();
	dest_ft[0] = 'A';
	dest_control[0] = 'A';
	concat_test(src_test, 26, expc_str, expc_ret);
}
