/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:27:12 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 00:59:49 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_open_file(char *file_name)
{
	size_t	name_len;
	int		fd;

	fd = -1;
	name_len = ft_strlen(file_name);
	if (name_len <= 4 || ft_strncmp(file_name + (name_len - 4), ".ber", 4))
		return (ft_error("invalid file name"), -1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error("cannot open file"), -1);
	return (fd);
}

// gnl modifié pour retourner tout le contenu
// du fichier, en une seule fois
int	ft_store_map(t_data *data, int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	if (!buffer)
		return (close(fd), ft_error("empty file"), -1);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (close(fd), ft_free_str(buffer),
			ft_error("map_data malloc failed"), -1);
	data->map->main = NULL;
	data->map->width = 0;
	data->map->height = 0;
	if (ft_split(buffer, '\n', data) == -1)
		return (close(fd), ft_free_str(buffer), -1);
	close(fd);
	ft_free_str(buffer);
	return (0);
}

int	ft_check_exit(char **map, int pos[2])
{
	if (map[pos[0] - 1][pos[1]] == 'P')
		return (0);
	if (map[pos[0]][pos[1] + 1] == 'P')
		return (0);
	if (map[pos[0] + 1][pos[1]] == 'P')
		return (0);
	if (map[pos[0]][pos[1] - 1] == 'P')
		return (0);
	return (-1);
}

char	**ft_copy_map(char **map)
{
	char	**map_cpy;
	size_t	map_rows;
	size_t	i;

	i = 0;
	map_rows = ft_strrlen(map);
	map_cpy = malloc(sizeof(char *) * (map_rows + 1));
	if (!map_cpy)
		return (ft_error("malloc failed in ft_copy_map"), NULL);
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
			return (ft_free_strr(map_cpy),
				ft_error("strdup failed in ft_copy_map"), NULL);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}
