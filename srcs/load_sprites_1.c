/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 01:49:33 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_load_sprites(t_data *data)
{
	int	*width;
	int	*height;

	data->sprite = malloc(sizeof(t_sprite));
	if (!data->sprite)
		return (ft_error("t_sprite malloc failed"), -1);
	ft_init_sprite(data);
	width = (int *)&data->sprite->width;
	height = (int *)&data->sprite->height;
	if (ft_load_sprites_background(data, width, height) == -1)
		return (-1);
	if (ft_load_sprites_player(data, width, height) == -1)
		return (-1);
	if (ft_load_sprites_enemy(data, width, height) == -1)
		return (-1);
	if (ft_load_sprites_collect(data, width, height) == -1)
		return (-1);
	if (ft_load_sprites_exit(data, width, height) == -1)
		return (-1);
	if (ft_load_sprites_gg_1(data, width, height) == -1)
		return (-1);
	return (0);
}

int	ft_load_sprites_gg_1(t_data *data, int *width, int *height)
{
	data->sprite->gg_0 = mlx_xpm_file_to_image(data->server, PATH_GG_0, width,
			height);
	if (!data->sprite->gg_0)
		return (ft_error("gg_0 sprite can't be opened"), -1);
	data->sprite->gg_1 = mlx_xpm_file_to_image(data->server, PATH_GG_1, width,
			height);
	if (!data->sprite->gg_1)
		return (ft_error("gg_1 sprite can't be opened"), -1);
	data->sprite->gg_2 = mlx_xpm_file_to_image(data->server, PATH_GG_2, width,
			height);
	if (!data->sprite->gg_2)
		return (ft_error("gg_2 sprite can't be opened"), -1);
	data->sprite->gg_3 = mlx_xpm_file_to_image(data->server, PATH_GG_3, width,
			height);
	if (!data->sprite->gg_3)
		return (ft_error("gg_3 sprite can't be opened"), -1);
	data->sprite->gg_4 = mlx_xpm_file_to_image(data->server, PATH_GG_4, width,
			height);
	if (!data->sprite->gg_4)
		return (ft_error("gg_4 sprite can't be opened"), -1);
	if (ft_load_sprites_gg_2(data, width, height) == -1
		|| ft_load_sprites_gg_3(data, width, height) == -1
		|| ft_load_sprites_gg_4(data, width, height) == -1)
		return (-1);
	return (0);
}

int	ft_load_sprites_gg_2(t_data *data, int *width, int *height)
{
	data->sprite->gg_5 = mlx_xpm_file_to_image(data->server, PATH_GG_5, width,
			height);
	if (!data->sprite->gg_5)
		return (ft_error("gg_5 sprite can't be opened"), -1);
	data->sprite->gg_6 = mlx_xpm_file_to_image(data->server, PATH_GG_6, width,
			height);
	if (!data->sprite->gg_6)
		return (ft_error("gg_6 sprite can't be opened"), -1);
	data->sprite->gg_7 = mlx_xpm_file_to_image(data->server, PATH_GG_7, width,
			height);
	if (!data->sprite->gg_7)
		return (ft_error("gg_7 sprite can't be opened"), -1);
	data->sprite->gg_8 = mlx_xpm_file_to_image(data->server, PATH_GG_8, width,
			height);
	if (!data->sprite->gg_8)
		return (ft_error("gg_8 sprite can't be opened"), -1);
	data->sprite->gg_9 = mlx_xpm_file_to_image(data->server, PATH_GG_9, width,
			height);
	if (!data->sprite->gg_9)
		return (ft_error("gg_9 sprite can't be opened"), -1);
	data->sprite->gg_10 = mlx_xpm_file_to_image(data->server, PATH_GG_10, width,
			height);
	if (!data->sprite->gg_10)
		return (ft_error("gg_10 sprite can't be opened"), -1);
	return (0);
}

int	ft_load_sprites_gg_3(t_data *data, int *width, int *height)
{
	data->sprite->gg_11 = mlx_xpm_file_to_image(data->server, PATH_GG_11, width,
			height);
	if (!data->sprite->gg_11)
		return (ft_error("gg_11 sprite can't be opened"), -1);
	data->sprite->gg_12 = mlx_xpm_file_to_image(data->server, PATH_GG_12, width,
			height);
	if (!data->sprite->gg_12)
		return (ft_error("gg_12 sprite can't be opened"), -1);
	data->sprite->win_0 = mlx_xpm_file_to_image(data->server, PATH_WIN_0, width,
			height);
	if (!data->sprite->win_0)
		return (ft_error("win_0 sprite can't be opened"), -1);
	data->sprite->win_1 = mlx_xpm_file_to_image(data->server, PATH_WIN_1, width,
			height);
	if (!data->sprite->win_1)
		return (ft_error("win_1 sprite can't be opened"), -1);
	data->sprite->lose_0 = mlx_xpm_file_to_image(data->server, PATH_LOSE_0,
			width, height);
	if (!data->sprite->lose_0)
		return (ft_error("lose_0 sprite can't be opened"), -1);
	data->sprite->lose_1 = mlx_xpm_file_to_image(data->server, PATH_LOSE_1,
			width, height);
	if (!data->sprite->lose_1)
		return (ft_error("lose_1 sprite can't be opened"), -1);
	return (0);
}

int	ft_load_sprites_gg_4(t_data *data, int *width, int *height)
{
	data->sprite->game_over = mlx_xpm_file_to_image(data->server,
			PATH_GAME_OVER, width, height);
	if (!data->sprite->game_over)
		return (ft_error("game_over sprite can't be opened"), -1);
	return (0);
}
