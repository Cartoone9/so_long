/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:10:12 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	*ft_which_player_exit(t_data *data, int which)
{
	static size_t	i;
	void			*ret;

	if (which == 13)
	{
		if (i < 16)
			ret = data->sprite->player_1;
		else if (i >= 16 && i < 24)
			ret = data->sprite->player_2;
		else if (i >= 24 && i < 32)
			ret = data->sprite->player_3;
		else
			ret = data->sprite->player_4;
		if (i < 40)
			i++;
		else
			i = 0;
	}
	else
		ret = ft_which_exit(data, i);
	return (ret);
}

void	*ft_which_exit(t_data *data, size_t i)
{
	void	*ret;

	if (data->game->collected != data->game->available)
		ret = data->sprite->chest_lock;
	else
	{
		if (i < 16)
			ret = data->sprite->chest_1;
		else if (i >= 16 && i < 24)
			ret = data->sprite->chest_2;
		else if (i >= 24 && i < 32)
			ret = data->sprite->chest_3;
		else
			ret = data->sprite->chest_4;
	}
	return (ret);
}

void	*ft_which_enemy(t_data *data)
{
	static size_t	passage;
	static size_t	i;
	void			*ret;

	passage++;
	if (i < 16)
		ret = data->sprite->enemy_1;
	else if (i >= 16 && i < 24)
		ret = data->sprite->enemy_2;
	else if (i >= 24 && i < 32)
		ret = data->sprite->enemy_3;
	else
		ret = data->sprite->enemy_4;
	if (passage == data->game->enemy)
	{
		passage = 0;
		if (i < 40)
			i++;
		else
			i = 0;
	}
	return (ret);
}

void	*ft_which_gg(t_data *data, size_t i)
{
	if (i == 0)
		return (data->sprite->gg_1);
	if (i == 1)
		return (data->sprite->gg_2);
	if (i == 2)
		return (data->sprite->gg_3);
	if (i == 3)
		return (data->sprite->gg_4);
	if (i == 4)
		return (data->sprite->gg_5);
	if (i == 5)
		return (data->sprite->gg_6);
	if (i == 6)
		return (data->sprite->gg_7);
	if (i == 7)
		return (data->sprite->gg_8);
	if (i == 8)
		return (data->sprite->gg_9);
	if (i == 9)
		return (data->sprite->gg_10);
	if (i == 10)
		return (data->sprite->gg_11);
	return (data->sprite->gg_12);
}

void	ft_paste_sprite(t_data *data, size_t x, size_t y, int which)
{
	char	*sprite_addr;
	char	*image_addr;
	size_t	i;
	size_t	j;

	sprite_addr = data->sprite->addr;
	i = 0;
	while (i < CS)
	{
		j = 0;
		image_addr = data->img->addr_t + x + y;
		if (which < 11)
			image_addr = data->img->addr_m + x + y;
		while (j < CS)
		{
			if (*(unsigned int *)sprite_addr != 0xFF000000)
				*(unsigned int *)image_addr = *(unsigned int *)sprite_addr;
			image_addr += (data->img->bpp / 8);
			sprite_addr += (data->img->bpp / 8);
			j++;
		}
		y += data->img->line_length;
		i++;
	}
}
