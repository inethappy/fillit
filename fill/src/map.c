void writing(t_tetr *tts)
{
	int	i;
	int j;
	char letter = 'A';
	char map[i][j];
	int max;
	int one_tetr = 0;
	int f = 0;

	max = 3; //kvadrat min pos4itat
	i = 0;
	j = 0;
	while (f < 4)
	{
		while (i != tts->x[one_tetr][f])
		{
			while (j != tts->y[one_tetr][f])
				{
					map[i][j] = '.';
					i++;
				}
			j++;
		}
		f++;
	}

	while (i !)





}
