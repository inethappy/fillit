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
	if (!(map = (char**)malloc(sizeof(char*) * i)))
		retrn (NULL);
	map[i] = NULL;
	j = -1;
	while (map[++j])
		map[j] = ft_strnew(i -1);
	j = -1;
	while (map[++j])
		ft_memset(map[j], '.', i);
	return (map);
}


void writing(t_tetr *tts, int c)
{
	char **map;
	char letter;

	map = empty_map(c);
	letter = 'A';


}
