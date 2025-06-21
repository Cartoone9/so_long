/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:01:42 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:24:39 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	ft_free_sprite_1(t_data *data)
{
	if (data->sprite->key_1)
		mlx_destroy_image(data->server, data->sprite->key_1);
	if (data->sprite->key_2)
		mlx_destroy_image(data->server, data->sprite->key_2);
	if (data->sprite->key_3)
		mlx_destroy_image(data->server, data->sprite->key_3);
	if (data->sprite->key_4)
		mlx_destroy_image(data->server, data->sprite->key_4);
	if (data->sprite->player_1)
		mlx_destroy_image(data->server, data->sprite->player_1);
	if (data->sprite->player_2)
		mlx_destroy_image(data->server, data->sprite->player_2);
	if (data->sprite->player_3)
		mlx_destroy_image(data->server, data->sprite->player_3);
	if (data->sprite->player_4)
		mlx_destroy_image(data->server, data->sprite->player_4);
	if (data->sprite->enemy_1)
		mlx_destroy_image(data->server, data->sprite->enemy_1);
	if (data->sprite->enemy_2)
		mlx_destroy_image(data->server, data->sprite->enemy_2);
	if (data->sprite->enemy_3)
		mlx_destroy_image(data->server, data->sprite->enemy_3);
	if (data->sprite->enemy_4)
		mlx_destroy_image(data->server, data->sprite->enemy_4);
}

void	ft_free_sprite_2(t_data *data)
{
	if (data->sprite->chest_lock)
		mlx_destroy_image(data->server, data->sprite->chest_lock);
	if (data->sprite->chest_1)
		mlx_destroy_image(data->server, data->sprite->chest_1);
	if (data->sprite->chest_2)
		mlx_destroy_image(data->server, data->sprite->chest_2);
	if (data->sprite->chest_3)
		mlx_destroy_image(data->server, data->sprite->chest_3);
	if (data->sprite->chest_4)
		mlx_destroy_image(data->server, data->sprite->chest_4);
	if (data->sprite->tile_t)
		mlx_destroy_image(data->server, data->sprite->tile_t);
	if (data->sprite->tile_b)
		mlx_destroy_image(data->server, data->sprite->tile_b);
	if (data->sprite->tile_l)
		mlx_destroy_image(data->server, data->sprite->tile_l);
	if (data->sprite->tile_r)
		mlx_destroy_image(data->server, data->sprite->tile_r);
	if (data->sprite->tile_tl)
		mlx_destroy_image(data->server, data->sprite->tile_tl);
	if (data->sprite->tile_tr)
		mlx_destroy_image(data->server, data->sprite->tile_tr);
	if (data->sprite->tile_bl)
		mlx_destroy_image(data->server, data->sprite->tile_bl);
}

void	ft_free_sprite_3(t_data *data)
{
	if (data->sprite->tile_br)
		mlx_destroy_image(data->server, data->sprite->tile_br);
	if (data->sprite->tile_wall)
		mlx_destroy_image(data->server, data->sprite->tile_grnd);
	if (data->sprite->tile_grnd)
		mlx_destroy_image(data->server, data->sprite->tile_wall);
	if (data->sprite->tile_white)
		mlx_destroy_image(data->server, data->sprite->tile_white);
	if (data->sprite->tile_black)
		mlx_destroy_image(data->server, data->sprite->tile_black);
	if (data->sprite->gg_0)
		mlx_destroy_image(data->server, data->sprite->gg_0);
	if (data->sprite->gg_1)
		mlx_destroy_image(data->server, data->sprite->gg_1);
	if (data->sprite->gg_2)
		mlx_destroy_image(data->server, data->sprite->gg_2);
	if (data->sprite->gg_3)
		mlx_destroy_image(data->server, data->sprite->gg_3);
	if (data->sprite->gg_4)
		mlx_destroy_image(data->server, data->sprite->gg_4);
	if (data->sprite->gg_5)
		mlx_destroy_image(data->server, data->sprite->gg_5);
	if (data->sprite->gg_6)
		mlx_destroy_image(data->server, data->sprite->gg_6);
}

void	ft_free_sprite_4(t_data *data)
{
	if (data->sprite->gg_7)
		mlx_destroy_image(data->server, data->sprite->gg_7);
	if (data->sprite->gg_8)
		mlx_destroy_image(data->server, data->sprite->gg_8);
	if (data->sprite->gg_9)
		mlx_destroy_image(data->server, data->sprite->gg_9);
	if (data->sprite->gg_10)
		mlx_destroy_image(data->server, data->sprite->gg_10);
	if (data->sprite->gg_11)
		mlx_destroy_image(data->server, data->sprite->gg_11);
	if (data->sprite->gg_12)
		mlx_destroy_image(data->server, data->sprite->gg_12);
	if (data->sprite->game_over)
		mlx_destroy_image(data->server, data->sprite->game_over);
	if (data->sprite->lose_0)
		mlx_destroy_image(data->server, data->sprite->lose_0);
	if (data->sprite->lose_1)
		mlx_destroy_image(data->server, data->sprite->lose_1);
	if (data->sprite->win_0)
		mlx_destroy_image(data->server, data->sprite->win_0);
	if (data->sprite->win_1)
		mlx_destroy_image(data->server, data->sprite->win_1);
}
