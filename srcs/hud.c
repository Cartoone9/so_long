/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:53:40 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:25:35 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_display_score(t_data *data)
{
	char	*value;
	char	*str;

	value = ft_itoa((int)data->game->moves);
	if (!value)
		return (ft_error("display score itoa failed"), -1);
	str = ft_strjoin("Steps : ", value);
	if (!str)
		return (free(value), ft_error("display score strjoin failed"), -1);
	mlx_string_put(data->server, data->win, 35, 22, 0xFFFFFF, str);
	free(value);
	free(str);
	return (0);
}

int	ft_display_keys(t_data *data)
{
	char	*collected;
	char	*available;
	char	*str;
	int		x;

	if (data->map->width < 7)
		return (1);
	collected = ft_itoa((int)data->game->collected);
	if (!collected)
		return (ft_error("display keys first itoa failed"), -1);
	available = ft_itoa((int)data->game->available);
	if (!available)
		return (free(collected), ft_error("display keys second itoa failed"),
			-1);
	str = ft_strjoin_keys("Keys : ", collected, available);
	if (!str)
		return (free(collected), free(available),
			ft_error("display score strjoin failed"), -1);
	x = data->map->width * CS - 106;
	mlx_string_put(data->server, data->win, x, 22, 0xFFFFFF, str);
	free(collected);
	free(available);
	free(str);
	return (0);
}
