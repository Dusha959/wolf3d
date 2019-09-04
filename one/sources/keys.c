/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsatterf <rsatterf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:07:28 by nbethany          #+#    #+#             */
/*   Updated: 2019/09/04 18:41:17 by rsatterf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		key_down(int key)
{
    if (key == KEY_ESC)
        exit(EXIT_SUCCESS);
    else if (key == KEY_SPACEBAR)
    {
        system("afplay -v 1.5 audio/gun_shot.wav &");
    }
    return (1);
}

int		key_trans(int key, t_wolf_3d *wolf)
{
	if (key == KEY_UP || key == KEY_W)
	{
			if (wolf->map[(int) (wolf->pos_x + wolf->dir_x * wolf->move_speed)][(int) wolf->pos_y] == 0)
				wolf->pos_x += wolf->dir_x * wolf->move_speed;
			if (wolf->map[(int) wolf->pos_x][(int) (wolf->pos_y + wolf->dir_y * wolf->move_speed)] == 0)
				wolf->pos_y += wolf->dir_y * wolf->move_speed;
			//system("afplay -v 0.5 audio/shag0.wav &");
    }
    else if (key == KEY_DOWN || key == KEY_S)
    {
            if (wolf->map[(int) (wolf->pos_x - wolf->dir_x * wolf->move_speed)][(int) wolf->pos_y] == 0)
                wolf->pos_x -= wolf->dir_x * wolf->move_speed;
            if (wolf->map[(int) wolf->pos_x][(int) (wolf->pos_y - wolf->dir_y * wolf->move_speed)] == 0)
                wolf->pos_y -= wolf->dir_y * wolf->move_speed;
		
    }

    else if (key == KEY_LEFT || key == KEY_A)
    {
        double oldDirX = wolf->dir_x;
        wolf->dir_x = wolf->dir_x * cos(wolf->rotate_speed) - wolf->dir_y * sin(wolf->rotate_speed);
        wolf->dir_y = oldDirX * sin(wolf->rotate_speed) + wolf->dir_y * cos(wolf->rotate_speed);
        double oldPlaneX = wolf->plane_x;
        wolf->plane_x = wolf->plane_x * cos(wolf->rotate_speed) - wolf->plane_y * sin(wolf->rotate_speed);
        wolf->plane_y = oldPlaneX * sin(wolf->rotate_speed) + wolf->plane_y * cos(wolf->rotate_speed);
    }
    else if (key == KEY_RIGHT || key == KEY_D)
    {
        double oldDirX = wolf->dir_x;
        wolf->dir_x = wolf->dir_x * cos(-wolf->rotate_speed) - wolf->dir_y * sin(-wolf->rotate_speed);
        wolf->dir_y = oldDirX * sin(-wolf->rotate_speed) + wolf->dir_y * cos(-wolf->rotate_speed);
        double oldPlaneX = wolf->plane_x;
        wolf->plane_x = wolf->plane_x * cos(-wolf->rotate_speed) - wolf->plane_y * sin(-wolf->rotate_speed);
        wolf->plane_y = oldPlaneX * sin(-wolf->rotate_speed) + wolf->plane_y * cos(-wolf->rotate_speed);
    }
		wolf->flag = 0;
        ray_caster(wolf);
    return (1);
}