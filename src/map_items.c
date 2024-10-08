/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:46:21 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/06 16:30:47 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	validations_items(t_map *copy_map)
{
	ft_printf("Players: %d\n", copy_map->player);
	ft_printf("Coins: %d\n", copy_map->coins);
	ft_printf("Exit: %d\n", copy_map->exit);
	if (copy_map->coins < 1
		|| copy_map->exit != 1 || copy_map->player != 1)
		handle_error(ERROR_ITEMS, 20, copy_map, NULL);
	else
	{
		ft_printf("Items ok\n");
	}
}

static int check_items(t_map *map)
{
    int x = 0;
    int y;

    while (x < map->rows)
    {
        y = 0;
        while (y < map->cols)
        {
            if (map->matrix[x][y] != '1' && map->matrix[x][y] != 'P' \
				&& map->matrix[x][y] != 'E' && map->matrix[x][y] != 'C' \
				&& map->matrix[x][y] != '0')
			{
				return 1;
			}
            y++;
        }
        x++;
    }
    return 0;
}
/************************VALIDATION MAIN **************************/

void	map_items(t_map *map)
{
	int	j;
	int	i;

	i = 1;
	while (i < map->rows - 1)
	{
		j = 1;
		while (j < map->cols - 1)
		{
			if (map->matrix[i][j] == 'P')
				map->player++;
			else if (map->matrix[i][j] == 'C')
				map->coins++;
			else if (map->matrix[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	if (check_items(map) == 1)
	{
        handle_error(ERROR_ITEMS, 20, map, NULL);
    }
	validations_items (map);
}
