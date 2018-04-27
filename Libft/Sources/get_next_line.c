/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 14:01:35 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 11:34:43 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

static int		ft_indexn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_chkstrbuffull(char *buf, char **str, char ***line)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	if (*str != NULL && ft_indexn(*str) >= 0)
	{
		tmp = ft_strdup(*str);
		i = ft_indexn(tmp);
		line[0][0] = ft_strsub(tmp, 0, i);
		*str = ft_strjoin((ft_strsub(tmp, i + 1, ft_strlen(tmp) - i)), buf);
		free(tmp);
		return (1);
	}
	return (0);
}

static int		ft_searchn(char *b, char **str, char ***line)
{
	char	*tmp;
	int		i;

	if (ft_indexn(b) >= 0)
	{
		i = ft_indexn(b);
		if (*str == NULL)
			line[0][0] = ft_strsub(b, 0, i);
		else
		{
			tmp = ft_strsub(b, 0, i);
			line[0][0] = ft_strjoin(*str, tmp);
			free(tmp);
		}
		if ((b[ft_indexn(b) + 1] != '\0'))
			str[0] = ft_strsub(b, i + 1, BUFF_SIZE - i);
		else
		{
			free(*str);
			str[0] = NULL;
		}
		return (1);
	}
	return (0);
}

static int		ft_check_final_str(char **str, char ***line)
{
	char *tmp;

	if (*str != NULL)
	{
		tmp = NULL;
		if (ft_indexn(*str) >= 0)
		{
			tmp = ft_strdup(*str);
			line[0][0] = ft_strsub(tmp, 0, ft_indexn(tmp));
			if (tmp[ft_indexn(tmp) + 1] == '\0')
				*str = NULL;
			else
				*str = ft_strsub(tmp, ft_indexn(tmp) + 1, ft_strlen(tmp));
		}
		else
		{
			line[0][0] = ft_strdup(*str);
			free(*str);
			*str = NULL;
		}
		free(tmp);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*str;
	char			*tmp;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || (ret = read(fd, buf, 0) < 0))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_chkstrbuffull(buf, &str, &line) || ft_searchn(buf, &str, &line))
			return (1);
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = ft_strdup(str);
			free(str);
			str = ft_strjoin(tmp, buf);
			free(tmp);
		}
	}
	if (ft_check_final_str(&str, &line))
		return (1);
	return (0);
}
