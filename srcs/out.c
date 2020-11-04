/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:56:44 by home              #+#    #+#             */
/*   Updated: 2020/11/04 01:32:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	out(t_option *choices, int at, int choice)
{
	char	*str_ptr;
	char	*end_ptr;

	str_ptr = choices[at].options[-1]; // -1 option gives ptr that is the option template.

	end_ptr = strchr(str_ptr, '*');
	printf("%.*s"BOLDCYAN"%s\e[0m%s\n", (int)(end_ptr - str_ptr), str_ptr, choices[at].options[choice], end_ptr + 1);
}