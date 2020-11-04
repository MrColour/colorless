/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:38:41 by home              #+#    #+#             */
/*   Updated: 2020/11/03 23:03:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define TIMES (100000)

//Due to zero index, usually this number is one lower that what you usually want.
#define MAX (99)

/*
** Program to verify the distribution the get_rand() function.
** This simply test that in the long run, there is an even and unbiased
** distribution between the numbers 0 and MAX.
*/
int	main(void)
{
	int	i;
	int	roll;
	int	freq[MAX + 1] = { 0 };

	srand(time(NULL));

	i = 0;
	while (i < TIMES)
	{
		roll = get_rand(MAX);
		freq[roll]++;
		i++;
	}

	i = 0;
	while (i <= MAX)
	{
		printf("N: %5d FREQ: %10d, with %f\n", i, freq[i], ((double)freq[i]) / TIMES);
		i++;
	}
	return (0);
}