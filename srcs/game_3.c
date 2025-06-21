/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:04:10 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_render_elements_onbackg_loop(t_data *data, size_t x, size_t y)
{
	int	ret;

	ret = 0;
	if (data->map->main[y][x] == 'C')
		ret = ft_which_sprite(data, x, y, 11);
	else if (data->map->main[y][x] == 'E')
		ret = ft_which_sprite(data, x, y, 12);
	else if (data->map->main[y][x] == 'P')
		ret = ft_which_sprite(data, x, y, 13);
	else if (data->map->main[y][x] == '#')
		ret = ft_which_sprite(data, x, y, 14);
	if (ret == -1)
		return (-1);
	return (0);
}

int	ft_which_sprite(t_data *data, size_t x, size_t y, int which)
{
	int		*bpp;
	int		*ll;
	int		*end;
	void	*img;

	x *= CS * (data->img->bpp / 8);
	y *= CS * data->img->line_length;
	bpp = &data->sprite->bpp;
	ll = &data->sprite->line_length;
	end = &data->sprite->endian;
	img = ft_choose_sprite(data, which);
	data->sprite->addr = mlx_get_data_addr(img, bpp, ll, end);
	if (!data->sprite->addr)
		return (ft_error("sprite get_data_addr failed"), -1);
	ft_paste_sprite(data, x, y, which);
	return (0);
}

void	*ft_choose_sprite(t_data *data, int which)
{
	void	*img;

	img = data->sprite->tile_white;
	if (which < 11)
		img = ft_which_background(data, which);
	if (which == 11)
		img = ft_which_key(data);
	if (which == 12 || which == 13)
		img = ft_which_player_exit(data, which);
	if (which == 14)
		img = ft_which_enemy(data);
	return (img);
}

void	*ft_which_background(t_data *data, int which)
{
	if (which == 0)
		return (data->sprite->tile_t);
	if (which == 1)
		return (data->sprite->tile_b);
	if (which == 2)
		return (data->sprite->tile_l);
	if (which == 3)
		return (data->sprite->tile_r);
	if (which == 4)
		return (data->sprite->tile_tl);
	if (which == 5)
		return (data->sprite->tile_tr);
	if (which == 6)
		return (data->sprite->tile_bl);
	if (which == 7)
		return (data->sprite->tile_br);
	if (which == 8)
		return (data->sprite->tile_wall);
	if (which == 9)
		return (data->sprite->tile_grnd);
	return (data->sprite->tile_black);
}

void	*ft_which_key(t_data *data)
{
	static size_t	passage;
	static size_t	i;
	void			*ret;
	size_t			on_map;

	passage++;
	on_map = data->game->available - data->game->collected;
	if (i < 16)
		ret = data->sprite->key_1;
	else if (i >= 16 && i < 24)
		ret = data->sprite->key_2;
	else if (i >= 24 && i < 32)
		ret = data->sprite->key_3;
	else
		ret = data->sprite->key_4;
	if (passage == on_map)
	{
		passage = 0;
		if (i < 40)
			i++;
		else
			i = 0;
	}
	return (ret);
}
