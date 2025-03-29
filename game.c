/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:19 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/30 00:26:37 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_interaction(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == COLLECTIBLE)
	{
		game->collected++;
		game->map.grid[y][x] = EMPTY;
	}
	else if (game->map.grid[y][x] == EXIT
		&& game->collected == game->map.collectibles)
	{
		ft_putstr_fd("You won in ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putendl_fd(" moves!", 1);
		close_window(game);
		return (1);
	}
	else if (game->map.grid[y][x] == EXIT)
		return (0);
	return (1);
}

int	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width
		|| new_y < 0 || new_y >= game->map.height)
		return (0);
	if (game->map.grid[new_y][new_x] == WALL)
		return (0);
	if (!handle_interaction(game, new_x, new_y))
		return (0);
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	game->map.player.x = new_x;
	game->map.player.y = new_y;
	render_game(game);
	return (1);
}
