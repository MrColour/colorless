/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:38:07 by home              #+#    #+#             */
/*   Updated: 2020/11/03 22:55:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <assert.h>
# include <time.h> // To seed srand();

# include <stdio.h>
# include <stdlib.h>

unsigned int	high_mask(int max);
unsigned int	get_rand(int max);

#endif