/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_memcpy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:34:47 by lrain             #+#    #+#             */
/*   Updated: 2025/12/17 18:37:37 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <memory.h>

void setUp(void)
{
}

void tearDown(void)
{
	// clean stuff up here
}

void test_all_asciis(void)
{
	char source[NUM_OF_ASCIIS] = {0};
	char target[NUM_OF_ASCIIS] = {0};
	char actual[NUM_OF_ASCIIS] = {0};

	get_all_asciis(source);
	memcpy(source, target, NUM_OF_ASCIIS);
	ft_memcpy(source, actual, NUM_OF_ASCIIS);
	check_against_stdlib(target, actual);
}

void test_n_limit(void)
{
	char source[NUM_OF_ASCIIS] = {0};
	char target[NUM_OF_ASCIIS] = {0};
	char actual[NUM_OF_ASCIIS] = {0};

	get_all_asciis(source);
	memcpy(source, target, NUM_OF_ASCIIS - 1);
	ft_memcpy(source, actual, NUM_OF_ASCIIS - 1);
	check_against_stdlib(target, actual);
}
