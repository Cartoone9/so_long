/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:53:40 by *******           #+#    #+#             */
/*   Updated: 2025/02/22 16:17:15 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2)
		return (ft_error("usage : ./so_long 'filename.ber'"), 1);
	fd = ft_open_file(av[1]);
	if (fd == -1)
		return (1);
	ft_null_init(&data);
	if (ft_store_map(&data, fd) == -1)
		return (ft_free_data(&data), 1);
	if (ft_check_map(&data, data.map->main) == -1)
		return (ft_free_data(&data), 1);
	if (ft_run_game(&data) == -1)
		return (ft_free_data(&data), 1);
	return (ft_free_data(&data), 1);
}
