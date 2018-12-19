#include <stdio.h>
#include "libft.h"

int ft_tetr_verif(char *buf)
{
	int fig = 0;
	int i = 0;
	if (ft_count_char(buf, '\n') != 4 || ft_count_char(buf, '#') != 4
		|| ft_count_char(buf, '.') != 12)
		return (0);
	if (ft_str_len_n(buf, '\n') != 4 || ft_str_len_n(buf + 5, '\n') != 4
		|| ft_str_len_n(buf + 10, '\n') != 4 || ft_str_len_n(buf + 15, '\n') != 4)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			fig = (buf[i - 1] == '#') ? (fig + 1) : (fig);
			fig = (buf[i + 1] == '#') ? (fig + 1) : (fig);
			fig = (buf[i - 5] == '#') ? (fig + 1) : (fig);
			fig = (buf[i + 5] == '#') ? (fig + 1) : (fig);
		}
		i++;
	}
//	printf("%d\n", fig);
	if (fig == 6 || fig == 8)
		return (1);
 	return (0);
}
