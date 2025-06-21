/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:53:40 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 04:21:48 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_key_press(int key_code, void *vdata)
{
	t_data	*data;
	int		key_code_id;

	data = (t_data *)vdata;
	if (key_code == 101)
		data->easter = 1;
	if (key_code == ESC)
		ft_close_window(data);
	if (data->end)
		return (0);
	if (data->pos == NULL)
		ft_init_pos(data);
	key_code_id = ft_key_id(key_code);
	if (key_code_id == 1)
		ft_move_player(data, data->pos->p[0], data->pos->p[1] - 1, LEFT);
	if (key_code_id == 2)
		ft_move_player(data, data->pos->p[0] - 1, data->pos->p[1], UP);
	if (key_code_id == 3)
		ft_move_player(data, data->pos->p[0], data->pos->p[1] + 1, RIGHT);
	if (key_code_id == 4)
		ft_move_player(data, data->pos->p[0] + 1, data->pos->p[1], DOWN);
	return (0);
}

int	ft_key_id(int key_code)
{
	if (key_code == LEFT || key_code == KEY_Q || key_code == KEY_A)
		return (1);
	else if (key_code == UP || key_code == KEY_Z || key_code == KEY_W)
		return (2);
	else if (key_code == RIGHT || key_code == KEY_D)
		return (3);
	else if (key_code == DOWN || key_code == KEY_S)
		return (4);
	return (0);
}

void	ft_move_player(t_data *data, int y, int x, int which)
{
	if (data->map->main[y][x] == '#')
	{
		data->end = 1;
		data->loser = 1;
		mlx_put_image_to_window(data->server, data->win,
			data->sprite->tile_grnd, data->pos->p[1] * CS,
			data->pos->p[0] * CS);
	}
	if (data->map->main[y][x] == 'E'
		&& data->game->collected == data->game->available)
	{
		data->end = 1;
		data->winner = 1;
		mlx_put_image_to_window(data->server, data->win,
			data->sprite->tile_grnd, data->pos->p[1] * CS,
			data->pos->p[0] * CS);
	}
	if (data->map->main[y][x] != '1' && (data->map->main[y][x] != 'E'
			|| data->winner))
		ft_move_player_utils(data, y, x, which);
}

void	ft_move_player_utils(t_data *data, int y, int x, int which)
{
	data->game->moves++;
	if (data->map->main[y][x] == 'C')
		data->game->collected++;
	data->map->main[y][x] = 'P';
	data->map->main[data->pos->p[0]][data->pos->p[1]] = '0';
	if (which == LEFT)
		data->pos->p[1]--;
	if (which == UP)
		data->pos->p[0]--;
	if (which == RIGHT)
		data->pos->p[1]++;
	if (which == DOWN)
		data->pos->p[0]++;
}
