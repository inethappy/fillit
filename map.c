#include "libft.h"
#include "fillit.h"

char **empty_map(int c)
{
	char **map;
	int	i;
	int j;
	int size;

	size = c * 4;
	i = 0;
	while ((i * i) < size)
		i++;
	if (!(map = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	map[i] = NULL;
	j = -1;
	while (++j < i)
		{
			map[j] = ft_strnew(i);
			ft_memset(map[j], '.', i);
		}
	//for printf:
	j = -1;
	printf("empty map:\n");
	while (map[++j])
		printf("%s\n", map[j]);//
	return (map);
}


void writing(t_tetr **tts, int c)
{
	char **map;
	char letter;
	int i;
	int j = 0;
	int tt = 0;
	//some shit_code
	map = empty_map(c);
	letter = 'A';
	i = 0;
	while (map[i] != '\0')
	{
		if (tts[tt]->x[j] == i)
			{
				while (tts[tt]->x[j] == i)
					{
						map[i][j] = letter;
						printf("%c\n", map[i][j]);
						j++;
					}
			}
		i++;
	}
}
