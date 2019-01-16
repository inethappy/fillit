/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:24:38 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/01/16 17:35:03 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* reading from file, verifying tetraminos */

int		ft_buf_verif(char *buf)
{
	int fig;
	int i;

	fig = 0;
	if (ft_count_char(buf, '\n') != 4 || ft_count_char(buf, '#') != 4
		|| ft_count_char(buf, '.') != 12)
		return (0);
	if (ft_str_len_n(buf, '\n') != 4 || ft_str_len_n(buf + 5, '\n') != 4
		|| ft_str_len_n(buf + 10, '\n') != 4
		|| ft_str_len_n(buf + 15, '\n') != 4)
		return (0);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			fig = (buf[i - 1] == '#') ? (fig + 1) : (fig);
			fig = (buf[i + 1] == '#') ? (fig + 1) : (fig);
			fig = (buf[i - 5] == '#') ? (fig + 1) : (fig);
			fig = (buf[i + 5] == '#') ? (fig + 1) : (fig);
		}
	}
	if (fig == 6 || fig == 8)
		return (1);
	return (0);
}

int		ft_file_work(char *file_name, char **bufs)
{
	int	fd;
	int	i;

	i = 0;
	while (i < 27)
		bufs[i++] = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (ft_verif(fd, bufs) == 0)
	{
		ft_putstr("error\n");
		ft_free_bufs(bufs);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int		ft_verif(int fd, char **bufs)
{
	char	buf[21];
	int		ret;
	int		i;

	i = -1;
	while ((ret = read(fd, buf, 20)) > 0 && ++i < 26)
	{
		buf[ret] = '\0';
		if (ret != 20 || ft_buf_verif(buf) == 0
			|| ((bufs[i] = ft_strdup(buf)) == NULL))
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
	int	i;

	i = -1;
	while (bufs[++i])
		free(bufs[i]);
	free(bufs);
}
