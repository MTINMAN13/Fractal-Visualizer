/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 01:52:26 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// #include <math.h>

// void calculate_smooth_color_two(double angle, int *r, int *g, int *b, int max_iter)
// {
//     // Modified color logic with additional hues for a smoother loop back to the initial color
//     double t = angle / (2 * M_PI);

//     // Use a sinusoidal function to create a smooth loop back
//     double modulation = 0.5 + 0.5 * sin((t + 0.5) * M_PI);

//     // Adjust t with the modulation factor to control the loop frequency
//     t = fmod(t + 0.5 * modulation, 1.0);

//     *r = (int)(9 * (1 - t) * t * t * t * 255);
//     *g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     *b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

//     // Additional hues for a more varied color palette
//     int lila_r = (int)(8.5 * (1 - t) * (1 - t) * t * t * 255);
//     int lila_g = (int)(9 * (1 - t) * t * t * t * 255);
//     int lila_b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);

//     int orange_r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     int orange_g = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
//     int orange_b = (int)(9 * (1 - t) * t * t * t * 255);

//     // Blend the additional hues with the primary color based on the iteration count
//     double blend_factor = (double)max_iter / 100.0; // Adjust as needed
//     *r = (int)((1 - blend_factor) * *r + blend_factor * lila_r);
//     *g = (int)((1 - blend_factor) * *g + blend_factor * lila_g);
//     *b = (int)((1 - blend_factor) * *b + blend_factor * lila_b);

//     // You can add more blending with other hues here based on the iteration count
//     // For example, blend with orange based on the iteration count
//     *r = (int)((1 - blend_factor) * *r + blend_factor * orange_r);
//     *g = (int)((1 - blend_factor) * *g + blend_factor * orange_g);
//     *b = (int)((1 - blend_factor) * *b + blend_factor * orange_b);
// }

#include <math.h>

// Function to convert HSL to RGB
static void hsl_to_rgb(double h, double s, double l, int *r, int *g, int *b) {
    double c = (1 - fabs(2 * l - 1)) * s;
    double x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
    double m = l - c / 2.0;

    double r_temp, g_temp, b_temp;

    if (h >= 0 && h < 60) {
        r_temp = c;
        g_temp = x;
        b_temp = 0;
    } else if (h >= 60 && h < 120) {
        r_temp = x;
        g_temp = c;
        b_temp = 0;
    } else if (h >= 120 && h < 180) {
        r_temp = 0;
        g_temp = c;
        b_temp = x;
    } else if (h >= 180 && h < 240) {
        r_temp = 0;
        g_temp = x;
        b_temp = c;
    } else if (h >= 240 && h < 300) {
        r_temp = x;
        g_temp = 0;
        b_temp = c;
    } else {
        r_temp = c;
        g_temp = 0;
        b_temp = x;
    }

    *r = (int)((r_temp + m) * 255);
    *g = (int)((g_temp + m) * 255);
    *b = (int)((b_temp + m) * 255);
}

static int ft_calculate_color_zero(int iteration, int max_iter, t_mlxdata *mlxdata, int x, int y)
{
    double	t;
    int		modifier;
    double	h;
    double	s;
    double	l;
    int		r, g, b;
    int		result;

    t = (double)iteration / max_iter;
    modifier = -121 % 16;
    h = mlxdata->c_offset + t * 360.0; // Use hue in degrees
    s = 1.0; // Full saturation
    l = 0.5; // Medium lightness

    hsl_to_rgb(h, s, l, &r, &g, &b);

    result = 0;
    for (int i = (modifier % 3); i < 3; ++i) // Adjust the starting point based on modifier
    {
        int shift_amount = 8 * i;
        int component;

        if (i == 0)
            component = r;
        else if (i == 1)
            component = g;
        else
            component = b;

        result |= (component << shift_amount);
    }

    return (result);
}


int ft_calculate_color(int iteration, int max_iter, t_mlxdata *mlxdata, int x, int y)
{
    double t = (double)iteration / max_iter;
    double angle;
    int r, g, b;
    int offset;
    int priority;
    double t_squared;
    double t_cubed;
    double gradient;
    double phase_shift;
    int i;
    int r_component, g_component, b_component;

    if (iteration == max_iter)
        return 0x000000;

    angle = 2 * M_PI * t + mlxdata->c_offset;
    r = g = b = 0;

    if (x == WIDTH / 2 && y == HEIGHT / 2)
    {
        r = g = b = (int)(255 * (0.7 + 0.3 * t));
    }
    else if (mlxdata->color_logic == 1)
    {
        offset = mlxdata->c_offset;
        priority = 3 % 20;
        t_squared = t * t;
        t_cubed = t_squared * t;
        gradient = sin(2 * M_PI * t + angle);
        phase_shift = M_PI / 2;
        i = 0;

        while (i < priority)
        {
            double temp = gradient;
            gradient = cos(2 * M_PI * t + phase_shift + angle);
            phase_shift += M_PI / 2;
            i++;
        }

        r = (int)((1 + gradient) * 0.5 * 255);
        g = (int)((1 + sin(2 * M_PI * t + phase_shift + angle)) * 0.5 * 255);
        b = (int)((1 + cos(2 * M_PI * t + phase_shift + angle)) * 0.5 * 255);
    }
    else if (mlxdata->color_logic == 2)
    {
        offset = mlxdata->c_offset;
        priority = (offset % 3);
        r_component = (int)(9 * (1 - t) * t * t * t * 255);
        g_component = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b_component = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

        if (priority == 0)
        {
            r = r_component;
            g = g_component;
            b = b_component;
        }
        else if (priority == 1)
        {
            r = g_component;
            g = b_component;
            b = r_component;
        }
        else
        {
            r = b_component;
            g = r_component;
            b = g_component;
        }

        // Increment the hue offset to cycle through shades
        mlxdata->c_offset += 0.001; // Adjust the increment as needed
    }
    else if (mlxdata->color_logic == 0)
    {
        // Call the function for color logic 0
        return ft_calculate_color_zero(iteration, max_iter, mlxdata, x, y);
    }
    else
    {
        return 0x000000;
    }

    return (r << 16) | (g << 8) | b;
}

