#include "fillit.h"

char	**ft_func1(char **map, t_tetr **tts, int fig)
{
	int		size;
	int		tmp;
	int		i;

	size = ft_strlen(map[0]);
	tmp = 0;
	while (tmp == 0)
	{
		tmp = ft_func2(map, tts, fig, size);
		if (tmp == 0)
		{
			//write(1, "2\n", 2);
			ft_free_bufs(map);
			size++;
			map = empty_map(size);
			i = 0;
			while (tts[i] && (tts[i]->p_y = 0) && (tts[i]->p_x = 0))
				i++;
		}
	}
	return (map);
}

int ft_func2(char **map, t_tetr **tts, int fig, int size)
{
	int		i;
	int		tmp;

	i = -1;
	while (i < size * size)
	{
		tmp = ft_put_check(map, tts, fig, size);
		if (tmp)
		{
			ft_paste_figure(map, tts, fig);
			if (tts[fig + 1] == NULL || ft_func2(map, tts, fig + 1, size))
				return (1);
			ft_erase_figure(map, tts, fig);
		}
		i++;
		tts[fig]->p_x = i % size;
		tts[fig]->p_y = i / size;
		}
	return (0);
}

int		ft_put_check(char **map, t_tetr **tts, int fig, int size)
{

	int		i;

	i = -1;
	while (++i < 4)
		if ((tts[fig]->p_y + tts[fig]->y[i] >= size) || (tts[fig]->p_x + tts[fig]->x[i] >= size))
			return (0);
	i = -1;
	while (++i < 4)
		if (map[tts[fig]->p_y + tts[fig]->y[i]][tts[fig]->p_x + tts[fig]->x[i]] != '.')
			return(0);
	return(1);
}

void ft_paste_figure(char **map, t_tetr **tts, int fig)
{
	int j;

	j = -1;
	while (++j < 4)
		map[tts[fig]->y[j] + tts[fig]->p_y][tts[fig]->x[j] + tts[fig]->p_x] = 65 + fig;
}

void ft_erase_figure(char **map, t_tetr **tts, int fig)
{
	int j;

	j = -1;
	while (++j < 4)
		map[tts[fig]->y[j] + tts[fig]->p_y][tts[fig]->x[j] + tts[fig]->p_x] = '.';
}

