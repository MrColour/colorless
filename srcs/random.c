/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:09:04 by home              #+#    #+#             */
/*   Updated: 2020/11/03 23:05:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	high_mask(int max)
{
	unsigned	clear;
	unsigned	mask;

	clear = __builtin_clz (max | 1);
	mask = (0xFFFFFFFF >> (clear));

	return (mask);
}

// unsigned int	get_rand(int max)
// {
// 	int				attempt;
// 	unsigned int	mask;

// 	assert(max > 0);
// 	assert(max < RAND_MAX);

// 	mask = high_mask(max);
// 	attempt = rand();
// 	attempt &= mask;
// 	while (attempt > max)
// 	{
// 		attempt = rand();
// 		attempt &= mask;
// 	}
// 	return (attempt);
// }

unsigned int	get_rand(int max)
{
	return (rand() % (max + 1));
}