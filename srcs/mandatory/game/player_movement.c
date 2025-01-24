/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:39:57 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	move_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i-1][j] == '1')
					break ;
				if (game->map->grid[i-1][j] == 'E' && game->coin != 0)
					return ;
				if (game->map->grid[i-1][j] == 'E' && game->coin == 0)
					close_game(game, END_WIN);
				is_next_coin(game, game->map->grid[i-1][j]);
				game->map->grid[i-1][j] = 'P';
				game->map->grid[i][j] = '0';
				display_map(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i][j-1] == '1')
					break ;
				if (game->map->grid[i][j-1] == 'E' && game->coin != 0)
					return ;
				if (game->map->grid[i][j-1] == 'E' && game->coin == 0)
					close_game(game, END_WIN);
				is_next_coin(game, game->map->grid[i][j-1]);
				game->map->grid[i][j-1] = 'P';
				game->map->grid[i][j] = '0';
				display_map(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i+1][j] == '1')
					break ;
				if (game->map->grid[i+1][j] == 'E' && game->coin != 0)
					return ;
				if (game->map->grid[i+1][j] == 'E' && game->coin == 0)
					close_game(game, END_WIN);
				is_next_coin(game, game->map->grid[i+1][j]);
				game->map->grid[i+1][j] = 'P';
				game->map->grid[i][j] = '0';
				display_map(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_right(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i][j+1] == '1')
					break ;
				if (game->map->grid[i][j+1] == 'E' && game->coin != 0)
					return ;
				if (game->map->grid[i][j+1] == 'E' && game->coin == 0)
					close_game(game, END_WIN);
				is_next_coin(game, game->map->grid[i][j+1]);
				game->map->grid[i][j+1] = 'P';
				game->map->grid[i][j] = '0';
				display_map(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_character(t_game *game, int keycode)
{
	if (keycode == W)
		move_up(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == D)
		move_right(game);
	else if (keycode == S)
		move_down(game);
}
