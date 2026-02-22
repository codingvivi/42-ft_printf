/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:33:21 by lrain             #+#    #+#             */
/*   Updated: 2026/02/22 16:42:25 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <assert.h>
#include <stdio.h>

int main(void) {

  printf("target:");
  int target_ret = printf(NULL);
  printf("<<END OF PRINT>>\n\n");

  printf("actual:");
  int actual_ret = ft_printf(NULL);
  printf("<<END OF PRINT>>\n\n");
  assert(target_ret == actual_ret);
  return (0);
}

