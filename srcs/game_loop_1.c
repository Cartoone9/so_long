/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:15:05 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_end_game(void *vdata)
{
	t_data			*data;

	data = (t_data *)vdata;
	if (data->end == 0)
		return (ft_game_latency(data));
	if (data->end == 1)
	{
		if (data->loser > 0 && data->loser < 6)
			ft_end_game_loser(data);
		else if (data->winner > 0 && data->winner < 6)
			ft_end_game_winner(data);
		else if (ft_black_fade(data) == 1)
			data->end++;
	}
	if (data->end > 1 && data->end < 30)
		ft_end_game_img(data);
	if (data->end == 30)
		ft_close_window(data);
	return (0);
}

long	get_current_time_ms(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

int	ft_game_latency(t_data *data)
{
	static long long	last_time;
	long long			current_time;
	long long			wait_time;

	current_time = get_current_time_ms();
	if (current_time - last_time >= LATENCY)
	{
		last_time = current_time;
		ft_render_elements(data);
	}
	else
	{
		wait_time = LATENCY - (current_time - last_time);
		if (wait_time > 0)
			usleep(wait_time * 1000);
	}
	return (0);
}

void	ft_end_game_loser(t_data *data)
{
	if (data->loser > 1)
	{
		usleep(WINLOSE_DELAY);
	}
	if (data->loser != 5)
	{
		if (data->loser % 2 != 0)
			mlx_put_image_to_window(data->server, data->win,
				data->sprite->lose_0, data->pos->p[1] * CS,
				data->pos->p[0] * CS);
		else
			mlx_put_image_to_window(data->server, data->win,
				data->sprite->lose_1, data->pos->p[1] * CS,
				data->pos->p[0] * CS);
	}
	data->loser++;
}

void	ft_end_game_winner(t_data *data)
{
	if (data->winner > 1)
	{
		usleep(WINLOSE_DELAY);
	}
	if (data->winner != 5)
	{
		if (data->winner % 2 != 0)
			mlx_put_image_to_window(data->server, data->win,
				data->sprite->win_0, data->pos->p[1] * CS,
				data->pos->p[0] * CS);
		else
			mlx_put_image_to_window(data->server, data->win,
				data->sprite->win_1, data->pos->p[1] * CS,
				data->pos->p[0] * CS);
	}
	data->winner++;
}
