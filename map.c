#include "libft.h"
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
	char **map;
	int j;

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

char	**ft_func1(char **map, t_tetr **tts, int fig)
{
	int		size;
	int		tmp;
	int		i;

	size = ft_strlen(map[0]);
	tmp = 0;
	while (tmp == 0)
	{
//		printf("ft_func1 WHILE size = %d\n", size);
		tmp = ft_func2(map, tts, fig, size);
//		printf("			ft_func1 tmp = %d\n", tmp);
		ft_print_map(map);
		if (tmp == 0)
		{
			ft_free_bufs(map);// may seqfault
			size++;
			map = empty_map(size);
			i = 0;
			while (tts[i] && (tts[i]->p_y = 0) && (tts[i]->p_x = 0)) /// 0 - i
				i++;
		}
	//ft_print_map(map);	
	}
	//ft_print_map(map);
	return (map);
}

int ft_func2(char **map, t_tetr **tts, int fig, int size)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < size * size)
	{
//		printf("ft_func2 WHILE\n");
		tmp = ft_put_check(map, tts, fig, size);
//		printf("ft_func2 while  tmp = %d, [%d, %d] \n", tmp, tts[fig]->p_x, tts[fig]->p_y);
//		printf("ft_func2 while fig = %d, [%d, %d] \n", fig, tts[fig]->p_x, tts[fig]->p_y);
		if (tmp)
		{
//			printf("ft_put_check is OK. i = %d, [%d, %d] \n", i, tts[fig]->p_x, tts[fig]->p_y);
			ft_paste_figure(map, tts, fig);
					/////
//			ft_print_map(map);
			if (tts[fig + 1] == NULL || ft_func2(map, tts, fig + 1, size))
				return (1);
			ft_erase_figure(map, tts, fig);
		}
		i++;
		tts[fig]->p_x = i % size;
		tts[fig]->p_y = i / size;
//		printf("ft_func2 i++.  i = %d, [%d, %d] \n", i, tts[fig]->p_x, tts[fig]->p_y);
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

void ft_print_map(char **map)
{
	int j;

	j = -1;
	//printf("map:\n");
	while (map[++j])
		write(1, map[j], ft_strlen(map[j]));
	write (1, "\n", 1);
}
