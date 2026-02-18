/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/unfinished/test_ft_strlcmp.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:41:48 by lrain             #+#    #+#             */
/*   Updated: 2025/12/09 17:50:52 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_helpers.h"
#include "unity.h"

extern int	ft_strncmp(char *s1, char *s2, unsigned int n);

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_greater(void)
{
	TEST_ASSERT_EQUAL_INT('t' - 'T',
		ft_strncmp("the quick brown fox jumps over the lazy dog!",
			"The quick brown fox jumps over the lazy dog!", 44));
}

void	test_lesser(void)
{
	TEST_ASSERT_EQUAL_INT('T' - 't',
		ft_strncmp("The quick brown fox jumps over the lazy dog!",
			"the quick brown fox jumps over the lazy dog!", 44));
}

void	test_equal_strings_and_input(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(LOWERCASE_LETTERS, LOWERCASE_LETTERS,
			26));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(UPPERCASE_LETTERS, UPPERCASE_LETTERS,
			26));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(DIGITS, DIGITS, 10));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(SPECIALS, SPECIALS,
}
