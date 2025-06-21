/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 01:50:06 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_load_sprites_collect(t_data *data, int *width, int *height)
{
	data->sprite->key_1 = mlx_xpm_file_to_image(data->server, PATH_KEY_1, width,
			height);
	if (!data->sprite->key_1)
		return (ft_error("key_1 sprite can't be opened"), -1);
	data->sprite->key_2 = mlx_xpm_file_to_image(data->server, PATH_KEY_2, width,
			height);
	if (!data->sprite->key_2)
		return (ft_error("key_2 sprite can't be opened"), -1);
	data->sprite->key_3 = mlx_xpm_file_to_image(data->server, PATH_KEY_3, width,
			height);
	if (!data->sprite->key_3)
		return (ft_error("key_3 sprite can't be opened"), -1);
	data->sprite->key_4 = mlx_xpm_file_to_image(data->server, PATH_KEY_4, width,
			height);
	if (!data->sprite->key_4)
		return (ft_error("key_4 sprite can't be opened"), -1);
	return (0);
}

int	ft_load_sprites_player(t_data *data, int *width, int *height)
{
	data->sprite->player_1 = mlx_xpm_file_to_image(data->server, PATH_PLAYER_1,
			width, height);
	if (!data->sprite->player_1)
		return (ft_error("player_1 sprite can't be opened"), -1);
	data->sprite->player_2 = mlx_xpm_file_to_image(data->server, PATH_PLAYER_2,
			width, height);
	if (!data->sprite->player_2)
		return (ft_error("player_2 sprite can't be opened"), -1);
	data->sprite->player_3 = mlx_xpm_file_to_image(data->server, PATH_PLAYER_3,
			width, height);
	if (!data->sprite->player_3)
		return (ft_error("player_3 sprite can't be opened"), -1);
	data->sprite->player_4 = mlx_xpm_file_to_image(data->server, PATH_PLAYER_4,
			width, height);
	if (!data->sprite->player_4)
		return (ft_error("player_4 sprite can't be opened"), -1);
	return (0);
}

int	ft_load_sprites_enemy(t_data *data, int *width, int *height)
{
	data->sprite->enemy_1 = mlx_xpm_file_to_image(data->server, PATH_ENEMY_1,
			width, height);
	if (!data->sprite->enemy_1)
		return (ft_error("enemy_1 sprite can't be opened"), -1);
	data->sprite->enemy_2 = mlx_xpm_file_to_image(data->server, PATH_ENEMY_2,
			width, height);
	if (!data->sprite->enemy_2)
		return (ft_error("enemy_2 sprite can't be opened"), -1);
	data->sprite->enemy_3 = mlx_xpm_file_to_image(data->server, PATH_ENEMY_3,
			width, height);
	if (!data->sprite->enemy_3)
		return (ft_error("enemy_3 sprite can't be opened"), -1);
	data->sprite->enemy_4 = mlx_xpm_file_to_image(data->server, PATH_ENEMY_4,
			width, height);
	if (!data->sprite->enemy_4)
		return (ft_error("enemy_4 sprite can't be opened"), -1);
	return (0);
}

int	ft_load_sprites_exit(t_data *data, int *width, int *height)
{
	data->sprite->chest_1 = mlx_xpm_file_to_image(data->server, PATH_CHEST_1,
			width, height);
	if (!data->sprite->chest_1)
		return (ft_error("chest_1 sprite can't be opened"), -1);
	data->sprite->chest_2 = mlx_xpm_file_to_image(data->server, PATH_CHEST_2,
			width, height);
	if (!data->sprite->chest_2)
		return (ft_error("chest_2 sprite can't be opened"), -1);
	data->sprite->chest_3 = mlx_xpm_file_to_image(data->server, PATH_CHEST_3,
			width, height);
	if (!data->sprite->chest_3)
		return (ft_error("chest_3 sprite can't be opened"), -1);
	data->sprite->chest_4 = mlx_xpm_file_to_image(data->server, PATH_CHEST_4,
			width, height);
	if (!data->sprite->chest_4)
		return (ft_error("chest_4 sprite can't be opened"), -1);
	data->sprite->chest_lock = mlx_xpm_file_to_image(data->server,
			PATH_CHEST_LOCK, width, height);
	if (!data->sprite->chest_lock)
		return (ft_error("chest_lock sprite can't be opened"), -1);
	return (0);
}
