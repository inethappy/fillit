#include "fillit.h"

int ft_buf_verif(char *buf)
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
	if (fig == 6 || fig == 8)
		return (1);
 	return (0);
}

int		ft_verif(char **bufs)
{
	char	buf[21];
	int		ret;
	int		fd;
	int		i;

	i = -1;
	if ((fd = open("test1.txt", O_RDONLY)) < 3)
		return 0;
	while ((ret = read(fd, buf, 20)) > 0 && ++i < 26)
	{
		buf[ret] = '\0';
		if (ret != 20 || ft_buf_verif(buf) == 0 || ((bufs[i] = ft_strdup(buf)) == NULL))
			return (0);
		if ((ret = read(fd, buf, 1)) == 0)
			return (1);
		buf[ret] = '\0';
		if (buf[0] != '\n')
			return (0);
	}
	return (0);
}

void	ft_free_bufs(char **bufs)
{
	int		i;

	i = 0;
	while (bufs[i])
			free(bufs[i++]);
	free(bufs);
}
