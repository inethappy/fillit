#include "fillit.h"

/*
void	ft_tmp_ttr_show(t_tetr **tts)
{
	int		i;

	while (tts[i])
	{

	}

}
*/
int main(void)
{
	char	**bufs;
	t_tetr	**tts;
	int		i;
	int		tmp;

	i = 0;
	bufs = (char**)malloc(sizeof(char*) * (26 + 1));
	while (i < 27 && bufs[i]) ////
		bufs[i++] = NULL;
	if (ft_verif(bufs) == 0)
	{
		write(1, "error\n", 6);
		ft_free_bufs(bufs);
//		system("leaks a.out");
		return (0);
	}
//	else /////
	 /////
	tmp = -1;
	while (bufs[++tmp])
	{
		printf("TETR %d:\n%s\n", tmp, bufs[tmp]);
	}
	//ostalnoe:
	if (!(tts =	ft_tetrs_make(bufs)))
		return (0);


	//ft_free_bufs(bufs);
	//ft_free_tts(tts);
//	system("leaks a.out");
	return 0;
}
