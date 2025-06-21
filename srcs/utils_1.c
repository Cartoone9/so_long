/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/22 16:23:26 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	ft_null_init(t_data *data)
{
	data->server = NULL;
	data->win = NULL;
	data->game = NULL;
	data->img = NULL;
	data->sprite = NULL;
	data->map = NULL;
	data->pos = NULL;
	data->end = 0;
	data->winner = 0;
	data->loser = 0;
	data->easter = 0;
}

void	ft_init_sprite(t_data *data)
{
	data->sprite->tile_t = NULL;
	data->sprite->tile_b = NULL;
	data->sprite->tile_l = NULL;
	data->sprite->tile_r = NULL;
	data->sprite->tile_tl = NULL;
	data->sprite->tile_tr = NULL;
	data->sprite->tile_bl = NULL;
	data->sprite->tile_br = NULL;
	data->sprite->tile_grnd = NULL;
	data->sprite->tile_wall = NULL;
	data->sprite->tile_white = NULL;
	data->sprite->tile_black = NULL;
	data->sprite->tile_br = NULL;
	ft_init_sprite_2(data);
	ft_init_sprite_3(data);
}

void	ft_init_sprite_2(t_data *data)
{
	data->sprite->key_1 = NULL;
	data->sprite->key_2 = NULL;
	data->sprite->key_3 = NULL;
	data->sprite->key_4 = NULL;
	data->sprite->player_1 = NULL;
	data->sprite->player_2 = NULL;
	data->sprite->player_3 = NULL;
	data->sprite->player_4 = NULL;
	data->sprite->enemy_1 = NULL;
	data->sprite->enemy_2 = NULL;
	data->sprite->enemy_3 = NULL;
	data->sprite->enemy_4 = NULL;
	data->sprite->chest_lock = NULL;
	data->sprite->chest_1 = NULL;
	data->sprite->chest_2 = NULL;
	data->sprite->chest_3 = NULL;
	data->sprite->chest_4 = NULL;
}

void	ft_init_sprite_3(t_data *data)
{
	data->sprite->game_over = NULL;
	data->sprite->win_0 = NULL;
	data->sprite->win_1 = NULL;
	data->sprite->lose_0 = NULL;
	data->sprite->lose_1 = NULL;
	data->sprite->gg_0 = NULL;
	data->sprite->gg_1 = NULL;
	data->sprite->gg_2 = NULL;
	data->sprite->gg_3 = NULL;
	data->sprite->gg_4 = NULL;
	data->sprite->gg_5 = NULL;
	data->sprite->gg_6 = NULL;
	data->sprite->gg_7 = NULL;
	data->sprite->gg_8 = NULL;
	data->sprite->gg_9 = NULL;
	data->sprite->gg_10 = NULL;
	data->sprite->gg_11 = NULL;
	data->sprite->gg_12 = NULL;
	data->sprite->width = CS;
	data->sprite->height = CS;
	data->sprite->addr = NULL;
	data->sprite->bpp = 0;
	data->sprite->line_length = 0;
	data->sprite->endian = 0;
}
