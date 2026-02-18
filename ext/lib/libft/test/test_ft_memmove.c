/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_memmove.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:48:03 by lrain             #+#    #+#             */
/*   Updated: 2025/12/18 09:25:14 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *source;
static char *target;
static char *actual;

void setUp(void)
{
}

void tearDown(void)
{
	if (source)
		free(source);
	if (target)
		free(target);
	if (actual)
		free(actual);
	source = target = actual = NULL;
	// printf("freed memory...\n");
}

void test_all_asciis(void)
{
	// printf("Beginning...\n");
	source = calloc(NUM_OF_ASCIIS + 1, sizeof(char));
	assert(source);
	target = calloc(NUM_OF_ASCIIS + 1, sizeof(char));
	assert(target);
	actual = calloc(NUM_OF_ASCIIS + 1, sizeof(char));
	assert(actual);

	// printf("Alloced memory...\n");
	get_all_asciis(source);
	// printf("Inited source...\n");
	memmove(source, target, NUM_OF_ASCIIS);
	// printf("Ran control...\n");
	ft_memmove(source, actual, NUM_OF_ASCIIS);
	// printf("Ran actual...\n");

	check_against_stdlib(target, actual);
	// printf("Ran test...\n");
}

void test_n_limit(void)
{
	source = calloc(sizeof(char), NUM_OF_ASCIIS + 1);
	assert(source);
	target = calloc(sizeof(char), NUM_OF_ASCIIS + 1);
	assert(target);
	actual = calloc(sizeof(char), NUM_OF_ASCIIS + 1);
	assert(actual);

	get_all_asciis(source);
	memmove(source, target, NUM_OF_ASCIIS - 1);
	ft_memmove(source, actual, NUM_OF_ASCIIS - 1);

	check_against_stdlib(target, actual);
}

void test_same_dest_src(void)
{
	source = malloc(sizeof(char) * NUM_OF_ASCIIS);
	assert(source);
	get_all_asciis(source);

	char *source_dup = strdup(source);
	assert(source_dup);

	target = source;
	actual = source_dup;

	memmove(target, source, NUM_OF_ASCIIS - 1);
	ft_memmove(actual, source_dup, NUM_OF_ASCIIS - 1);

	check_against_stdlib(target, actual);

	if (source_dup)
		free(source_dup);
	source_dup = NULL;

	target = NULL;
	actual = NULL;
}

void test_smaller_src(void)
{
	source = malloc(sizeof(char) * NUM_OF_ASCIIS);
	assert(source);
	get_all_asciis(source);

	char *source_dup = strdup(source);
	assert(source_dup);

	target = source + 1;
	actual = source_dup + 1;

	memmove(target, source, NUM_OF_ASCIIS - 1);
	ft_memmove(actual, source_dup, NUM_OF_ASCIIS - 1);

	check_against_stdlib(target, actual);

	if (source_dup)
		free(source_dup);
	source_dup = NULL;

	target = NULL;
	actual = NULL;
}

void test_larger_src(void)
{
	char container_target[NUM_OF_ASCIIS + 1] = {0};
	source = container_target + 1;
	get_all_asciis(source);

	char  container_actual[NUM_OF_ASCIIS + 1] = {0};
	char *source_actual = container_actual + 1;
	get_all_asciis(source_actual);

	target = container_target;
	actual = container_actual;

	memmove(target, source, NUM_OF_ASCIIS);
	ft_memmove(actual, source_actual, NUM_OF_ASCIIS);

	check_against_stdlib(target, actual);

	source = NULL;
	target = NULL;
	actual = NULL;
}
