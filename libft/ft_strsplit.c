/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:04:48 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:04:50 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *str, char c)
{
	size_t		res;
	int			i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			res++;
		}
		while (str[i] && str[i] == c)
			i++;
	}
	return (res);
}

static int		ft_wordlen(char const *str, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s)
		return (0);
	if ((res = (char**)malloc(sizeof(res) * ft_countwords(s, c) + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		k = 0;
		if ((res[i] = ft_strnew(ft_wordlen(&s[j], c) + 1)) == NULL)
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			res[i][k++] = s[j++];
		res[i][k] = '\0';
		i++;
	}
	res[i] = 0;
	return (res);
}
