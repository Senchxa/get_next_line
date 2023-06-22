/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:20:34 by dnoll             #+#    #+#             */
/*   Updated: 2023/06/03 14:19:40 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	lines;
	char	*line;

	lines = 1;
	fd = open("cat.txt", O_RDONLY);



	if (fd == -1)
	{
		printf("Error\n");
		return (0);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%d->%s", lines++, line);
	}
	return (0);



}
