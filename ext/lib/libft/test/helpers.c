/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:09:56 by lrain             #+#    #+#             */
/*   Updated: 2025/12/17 18:42:02 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <stddef.h>

void get_all_asciis(char *str_ptr)
{
	for (int i = 1; i < 128; i++)
		str_ptr[i] = i;
}

void compare_as_bools(bool target, bool actual)
{
	VERBOSE_PRINT("target: %d, actual: %d", tgt, act);
	TEST_ASSERT(target == actual);
}

void check_against_stdlib(char *tgt, char *act)
{
	VERBOSE_PRINT("target: %d, actual: %d", tgt, act);
	TEST_ASSERT_EQUAL_STRING(tgt, act);
}
