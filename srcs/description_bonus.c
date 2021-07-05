/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:40:42 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:40:43 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_description(void)
{
	printf("Operate\n- ESC key & × button: exit program\n");
	printf("- Arrow keys: moving\n- I key: reset to beginning\n");
	printf("- W & S keys: contorol depth\n");
	printf("- E & D keys:contorol divergence value\n");
	printf("- K & L keys:contorol Zoom in & out value\n");
	printf("- R & G & B keys: change the color\n\n");
	printf("In julia set\n- Z & X keys: contorol actual number\n");
	printf("- C & V keys: contorol complex number\n");
}
