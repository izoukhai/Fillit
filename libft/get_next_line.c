/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:02:57 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:02:58 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static int		ft_strichr(char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static t_list	*get_file(t_list **list, int fd)
{
	t_list		*cur;

	cur = *list;
	while (cur)
	{
		if ((int)cur->content_size == fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew("\0", fd);
	ft_lstadd(list, cur);
	return (cur);
}

int				get_line(t_list **file, char **line)
{
	int			cut;
	char		*tmp;

	if ((*file)->content && ft_strchr((*file)->content, '\n'))
	{
		cut = ft_strichr((*file)->content, '\n');
		*line = ft_strsub((*file)->content, 0, cut);
		tmp = ft_strdup((*file)->content + cut + 1);
		free((*file)->content);
		(*file)->content = tmp;
		return (1);
	}
	if ((*file)->content)
	{
		*line = ft_strdup((*file)->content);
		ft_strclr((*file)->content);
		return (1);
	}
	else
		return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*file;
	char			*tmp;
	t_list			*cur;

	cur = get_file(&file, fd);
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (ft_strchr(cur->content, '\n'))
		return (get_line(&cur, line));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(cur->content, buf);
		free(cur->content);
		cur->content = tmp;
		if (ft_strchr(cur->content, '\n'))
			break ;
	}
	if (!ft_strlen(cur->content))
		return (0);
	if (get_line(&cur, line) == 1)
		return (1);
	return (0);
}
