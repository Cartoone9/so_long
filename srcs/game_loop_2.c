/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:25:26 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_black_fade(t_data *data)
{
	static size_t	y;
	size_t			x;

	x = 0;
	if (y == 0)
		y = CS;
	if (y < (CS * data->map->height) - CS)
	{
		mlx_string_put(data->server, data->win, x, y, 0x000000, FADE_TEXT);
		mlx_string_put(data->server, data->win, x + 1, y, 0x000000,
			FADE_TEXT);
		mlx_string_put(data->server, data->win, x + 2, y, 0x000000,
			FADE_TEXT);
		if (data->map->height < 75)
			usleep(FADE_DELAY - (data->map->height * 100));
		y++;
		return (0);
	}
	return (1);
}

void	ft_end_game_img(t_data *data)
{
	static size_t	i;
	void			*img;

	if (data->loser)
		img = data->sprite->game_over;
	else if (!data->easter)
		img = data->sprite->gg_0;
	else
		img = ft_which_gg(data, i);
	mlx_put_image_to_window(data->server, data->win, img,
		data->map->width * CS / 2 - 48, data->map->height * CS
		/ 2 - 42);
	usleep(ANIMATION_DELAY);
	i++;
	if (i == 12)
		i = 0;
	data->end++;
}
