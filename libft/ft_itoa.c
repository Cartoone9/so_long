/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:14:51 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:41:04 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

static void		ft_rec_fill(size_t length, char *ret, int n);
static size_t	ft_intlen(int n);

char	*ft_itoa(int n)
{
	size_t	single_digit;
	size_t	length;
	char	*ret;

	single_digit = 0;
	length = ft_intlen(n);
	if (length == 1)
	{
		single_digit = 1;
		length++;
	}
	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);
	ret[length] = '\0';
	if (single_digit == 1)
	{
		ret[0] = '0';
		ret[1] = n + 48;
		ret[2] = '\0';
	}
	else
		ft_rec_fill((length - 1), ret, n);
	return (ret);
}

static void	ft_rec_fill(size_t length, char *ret, int n)
{
	if (n >= 10 && length > 0)
	{
		ft_rec_fill((length - 1), ret, n / 10);
	}
	ret[length] = (n % 10) + 48;
}

static size_t	ft_intlen(int n)
{
	size_t	sum;
	long	n_ln;

	sum = 0;
	n_ln = (long)n;
	if (n_ln == 0)
		return (1);
	if (n_ln < 0)
	{
		n_ln = -(n_ln);
		sum++;
	}
	while (n_ln > 0)
	{
		n_ln /= 10;
		sum++;
	}
	return (sum);
}
