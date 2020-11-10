/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:37:28 by home              #+#    #+#             */
/*   Updated: 2020/11/10 14:22:40 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_option	convert_file(char *option_name)
{
	char		*file_name;
	char		*str;
	t_option	result;
	int			len;
	int			i;

	asprintf(&file_name, CONFIG_DIR"%s"FILE_TYPE, option_name);

	str = extract_file(file_name);
	len = count_occur("\n",	str);
	i = 0;
	result.len = len;
	result.options = calloc(len, sizeof(*(result.options)));
	str = strtok(str, "\n");
	while (str != NULL)
	{
		result.options[i] = str;
		str = strtok(NULL, "\n");
		i++;
	}
	free(file_name);
	result.options = &(result.options[1]);
	result.len--;

	return (result);
}

t_option	*create_options(char **options, int count)
{
	int			i;
	t_option	*result;

	i = 0;
	result = calloc(count, sizeof(*result));
	while (i < count)
	{
		result[i] = convert_file(options[i]);
		i++;
	}
	return (result);
}

int	main(int aa, char **args)
{
	int			i;
	int			pick;
	t_option	*choices;

	assert(aa > 1);
	chdir(dirname(args[0]));

	getentropy(&i, 4);
	srand(time(NULL) * i);
	choices = create_options(&args[1], aa - 1);

	i = 0;
	while (i + 1 < aa)
	{
		pick = get_rand(choices[i].len - 1);
		while (choices[i].options[pick][0] == '/')
			pick = get_rand(choices[i].len);
		out(choices, i, pick);
		i++;
	}
	return (0);
}