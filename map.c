/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:35:56 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/01/16 15:49:34 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_optimal_map_size(t_tetr **tts)
{
	int	i;
	int size;

	i = 0;
	while (tts[i])
		i++;
	size = i * 4;
	i = 0;
	while ((i * i) < size)
		i++;
	return (i);
}

char	**empty_map(int i)
{
	char	**map;
	int		j;

	if (!(map = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	map[i] = NULL;
	j = -1;
	while (++j < i)
	{
		map[j] = ft_strnew(i);
		ft_memset(map[j], '.', i);
	}
	return (map);
}

void	ft_print_map(char **map)
{
	int j;

	j = -1;
	while (map[++j])
	{
		ft_putstr(map[j]);
		ft_putstr("\n");
	}
}
