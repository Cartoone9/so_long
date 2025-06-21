/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:03 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:40:02 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

static int	ft_split_suite(char **strr, const char *s, char c, t_data *data);

int	ft_split(char const *s, char c, t_data *data)
{
	char	**strr;
	int		j;

	if (ft_check_empty(s, c))
		return (ft_error("empty line in map"), -1);
	strr = malloc(sizeof(char *) * (ft_strcnt(s, c) + 3));
	if (strr == NULL)
		return (ft_error("buffer split error"), -1);
	if (ft_add_topline(strr, s, c) == -1)
		return (ft_error("add_topline split error"), -1);
	j = ft_split_suite(strr, s, c, data);
	if (j == -1)
		return (ft_error("buffer split error"), -1);
	if (ft_add_botline(strr, s, c, j) == -1)
		return (ft_error("add_topline split error"), -1);
	strr[++j] = NULL;
	data->map->main = strr;
	return (0);
}

static int	ft_split_suite(char **strr, const char *s, char c, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			strr[j] = malloc(sizeof(char) * (ft_nextch(&s[i], c) + 3));
			if (strr[j] == NULL)
				return (ft_free_strr(strr), -1);
			k = 0;
			strr[j][k++] = '*';
			while (s[i] && s[i] != c)
				strr[j][k++] = s[i++];
			strr[j][k++] = '*';
			strr[j++][k] = '\0';
		}
	}
	ft_update_data_map(data, j, k);
	return ((int)j);
}

void	ft_update_data_map(t_data *data, size_t j, size_t k)
{
	data->map->width = k;
	data->map->height = j + 1;
}

size_t	ft_strcnt(const char *str, char c)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != c)
			sum++;
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
			sum++;
		i++;
	}
	return (sum);
}

size_t	ft_nextch(const char *str, char c)
{
	size_t	sum;

	sum = 0;
	while (str[sum] && str[sum] != c)
		sum++;
	return (sum);
}
