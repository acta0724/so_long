/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:47 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/30 02:14:49 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static char	**create_visited_map(t_game *game)
{
	char	**visited;
	int		i;

	visited = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!visited)
		error_exit(ERR_MEM);
	i = 0;
	while (i < game->map.height)
	{
		visited[i] = ft_strdup(game->map.grid[i]);
		if (!visited[i])
		{
			free_map(visited, i);
			error_exit(ERR_MEM);
		}
		i++;
	}
	visited[i] = NULL;
	return (visited);
}

void	flood_fill(t_game *game, char **visited, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return ;
	if (visited[y][x] == WALL || visited[y][x] == 'V')
		return ;
	if (visited[y][x] == COLLECTIBLE)
		game->map.collectibles_found++;
	if (visited[y][x] == EXIT)
		game->map.exit_found = 1;
	visited[y][x] = 'V';
	flood_fill(game, visited, x + 1, y);
	flood_fill(game, visited, x - 1, y);
	flood_fill(game, visited, x, y + 1);
	flood_fill(game, visited, x, y - 1);
}

void	check_path(t_game *game)
{
	char	**visited;

	visited = create_visited_map(game);
	game->map.collectibles_found = 0;
	game->map.exit_found = 0;
	flood_fill(game, visited, game->map.player.x, game->map.player.y);
	free_map(visited, game->map.height);
	if (game->map.collectibles_found != game->map.collectibles
		|| !game->map.exit_found)
		error_exit(ERR_PATH);
}
