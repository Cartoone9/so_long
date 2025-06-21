/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:04 by *******           #+#    #+#             */
/*   Updated: 2025/02/03 18:55:16 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	sum;

	if (!str)
		return (0);
	sum = 0;
	while (str[sum])
		sum++;
	return (sum);
}

size_t	ft_strrlen(char **strr)
{
	size_t	ret;

	if (!strr || !strr[0])
		return (0);
	ret = 0;
	while (strr[ret])
		ret++;
	return (ret);
}
