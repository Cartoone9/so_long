/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:03 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:33:04 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_add_botline(char **strr, char const *s, char c, int j)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_nextch(&s[i], c);
	strr[j] = malloc(sizeof(char) * (ft_nextch(&s[i], c) + 3));
	if (!strr[j])
		return (ft_free_strr(strr), -1);
	while (i < length + 2)
	{
		strr[j][i] = '*';
		i++;
	}
	strr[j][i] = '\0';
	return (0);
}

int	ft_add_topline(char **strr, char const *s, char c)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_nextch(&s[i], c);
	strr[0] = malloc(sizeof(char) * (ft_nextch(&s[i], c) + 3));
	if (!strr[0])
		return (ft_free_strr(strr), -1);
	while (i < length + 2)
	{
		strr[0][i] = '*';
		i++;
	}
	strr[0][i] = '\0';
	return (0);
}

int	ft_check_empty(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (s[0] == '\n')
		return (1);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == c)
			return (1);
		i++;
	}
	return (0);
}
