/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:20:33 by home              #+#    #+#             */
/*   Updated: 2020/11/10 14:22:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*extract_file(char *file_name)
{
	char	*str;
	FILE	*file;
	long	l;

	file = fopen(file_name, "r");

	assert(file != NULL);
	fseek(file, 0L, SEEK_END);
	l = ftell(file);
	str = calloc(l + 1, 1);
	rewind(file);
	fread(str, l, 1, file);
	fclose(file);

	return (str);
}

int	count_occur(char *key, char *src)
{
	int		occur;
	int		l;

	occur = 0;
	l = strlen(key);
	while ((src = strstr(src, key)) != NULL)
	{
		occur++;
		src += l;
	}
	return (occur);
}