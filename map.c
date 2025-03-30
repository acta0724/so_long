/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:42 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/31 00:44:42 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	count_map_height(char *map_file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILE);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	if (height == 0)
		error_exit(ERR_MAP);
	return (height);
}

int	parse_map(t_game *game, char *map_file)
{
	int		fd;
	int		i;
	char	*line;

	game->map.height = count_map_height(map_file);
	game->map.grid = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		error_exit(ERR_MEM);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILE);
	i = -1;
	while (++i < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map.grid[i] = line;
	}
	game->map.grid[i] = NULL;
	close(fd);
	game->map.width = ft_strlen(game->map.grid[0]);
	return (1);
}

void	validate_map(t_game *game)
{
	check_rectangular(game);
	check_walls(game);
	check_chars(game);
	check_components(game);
}
