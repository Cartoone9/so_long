/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 01:50:51 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_load_sprites_background(t_data *data, int *width, int *height)
{
	data->sprite->tile_t = mlx_xpm_file_to_image(data->server, PATH_TILE_TOP,
			width, height);
	if (!data->sprite->tile_t)
		return (ft_error("tile_top sprite can't be opened"), -1);
	data->sprite->tile_b = mlx_xpm_file_to_image(data->server, PATH_TILE_BOT,
			width, height);
	if (!data->sprite->tile_b)
		return (ft_error("tile_bot sprite can't be opened"), -1);
	data->sprite->tile_l = mlx_xpm_file_to_image(data->server, PATH_TILE_LEFT,
			width, height);
	if (!data->sprite->tile_l)
		return (ft_error("tile_left sprite can't be opened"), -1);
	data->sprite->tile_r = mlx_xpm_file_to_image(data->server, PATH_TILE_RIGHT,
			width, height);
	if (!data->sprite->tile_r)
		return (ft_error("tile_right sprite can't be opened"), -1);
	data->sprite->tile_tl = mlx_xpm_file_to_image(data->server,
			PATH_TILE_TOP_LEFT, width, height);
	if (!data->sprite->tile_tl)
		return (ft_error("tile_tl sprite can't be opened"), -1);
	data->sprite->tile_tr = mlx_xpm_file_to_image(data->server,
			PATH_TILE_TOP_RIGHT, width, height);
	if (!data->sprite->tile_tr)
		return (ft_error("tile_tr sprite can't be opened"), -1);
	return (ft_load_sprites_background_suite(data, width, height));
}

int	ft_load_sprites_background_suite(t_data *data, int *width, int *height)
{
	data->sprite->tile_bl = mlx_xpm_file_to_image(data->server,
			PATH_TILE_BOT_LEFT, width, height);
	if (!data->sprite->tile_bl)
		return (ft_error("tile_bl sprite can't be opened"), -1);
	data->sprite->tile_br = mlx_xpm_file_to_image(data->server,
			PATH_TILE_BOT_RIGHT, width, height);
	if (!data->sprite->tile_br)
		return (ft_error("tile_br sprite can't be opened"), -1);
	data->sprite->tile_grnd = mlx_xpm_file_to_image(data->server,
			PATH_TILE_GROUND, width, height);
	if (!data->sprite->tile_grnd)
		return (ft_error("tile_grnd sprite can't be opened"), -1);
	data->sprite->tile_wall = mlx_xpm_file_to_image(data->server,
			PATH_TILE_WALL, width, height);
	if (!data->sprite->tile_wall)
		return (ft_error("tile_wall sprite can't be opened"), -1);
	data->sprite->tile_white = mlx_xpm_file_to_image(data->server,
			PATH_TILE_WHITE, width, height);
	if (!data->sprite->tile_white)
		return (ft_error("tile_white sprite can't be opened"), -1);
	data->sprite->tile_black = mlx_xpm_file_to_image(data->server,
			PATH_TILE_BLACK, width, height);
	if (!data->sprite->tile_black)
		return (ft_error("tile_black sprite can't be opened"), -1);
	return (0);
}
