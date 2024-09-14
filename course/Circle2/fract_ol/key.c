/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:47:36 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/25 21:26:19 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int     key_hook(int key_code/*, t_fractal *fractal*/)
{
    printf("%d", key_code);
    if (key_code == ESC)
        exit(1);
    return(0);
}

int     lets_exit(int mouse_code)
{
    printf("%d", mouse_code);
    exit(1);
    return(0);
}