/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:38:07 by home              #+#    #+#             */
/*   Updated: 2020/11/10 13:20:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <assert.h>
# include <time.h> // To seed srand();

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <unistd.h>
# include <sys/random.h>

# include "color.h"

#define FILE_TYPE ".colorless"
#define CONFIG_DIR "config/"

typedef struct	s_option
{
	int			len;
	char		**options;
}				t_option;

unsigned int	high_mask(int max);
unsigned int	get_rand(int max);

void			out(t_option *choices, int at, int choice);

char			*extract_file(char *file_name);
int				count_occur(char *key, char *src);

#endif