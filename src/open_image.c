/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkutilko <zkutilko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:39:39 by zkutilko          #+#    #+#             */
/*   Updated: 2024/10/04 15:39:39 by zkutilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include "so_long.h"
// #include <time.h>   // For time

// #define WIDTH 500
// #define HEIGHT 500

// int main()
// {
//     void    *mlx_connection;
//     void    *mlx_window;
//     int     x;
//     int     y;

//     srand(time(NULL)); // Seed the random number generator

//     mlx_connection = mlx_init();
//     mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "My 1* window");

//     y = HEIGHT * 0.1; // Start drawing from 10% down
//     while (y < HEIGHT * 0.9) // Draw until 90% height
//     {
//         x = WIDTH * 0.1; // Start from 10% width
//         while (x < WIDTH * 0.9) // Draw until 90% width
//         {
//             mlx_pixel_put(mlx_connection, mlx_window, x, y, rand() % 0x1000000); // Random color
//             x++;
//         }
//         y++;
//     }

//     // Uncomment to draw a string
//     // mlx_string_put(mlx_connection, mlx_window, WIDTH * 0.8, HEIGHT * 0.95, rand() % 0x1000000, "My Pollock");

//     mlx_loop(mlx_connection); // Enter the event loop
// }
#include <stdio.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

typedef struct {
	int x;
	int y;
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
} Pozice;

void draw_player(Pozice *hrac_pozice) {
	// Vymazání okna
	mlx_clear_window(hrac_pozice->mlx_ptr, hrac_pozice->win_ptr);
	// Vložení obrázku hráče na danou pozici
	mlx_put_image_to_window(hrac_pozice->mlx_ptr, hrac_pozice->win_ptr, hrac_pozice->img_ptr, hrac_pozice->x, hrac_pozice->y);
}

// Přidání __attribute__((unused)) k parametru
int key_hook(int keycode, Pozice *hrac_pozice) {
	if (keycode == 65307) { // ESC key
		exit(0); // Ukončení programu
	}
	else if (keycode == 119)
		hrac_pozice->y -= 10;
// Bez dalších akcí
	draw_player(hrac_pozice);
	return 0;
}

int main()
{
	Pozice hrac_pozice;

	// Inicializace MinilibX
	hrac_pozice.mlx_ptr = mlx_init();
	hrac_pozice.win_ptr = mlx_new_window(hrac_pozice.mlx_ptr, 800, 600, "Moje Okno");

	// Načtení XPM obrázku
	hrac_pozice.img_ptr = mlx_xpm_file_to_image(hrac_pozice.mlx_ptr, "images/player.xpm", &(hrac_pozice.x), &(hrac_pozice.y));
	if (hrac_pozice.img_ptr == NULL) {
		fprintf(stderr, "Chyba při načítání obrázku!\n");
		return 1;
	}

	// Nastavení pozice hráče
	hrac_pozice.x = 400; // Střed okna
	hrac_pozice.y = 300; // Střed okna

	// Vykreslení hráče
	draw_player(&hrac_pozice);

	// Registrace události pro klávesnici
	mlx_key_hook(hrac_pozice.win_ptr, (int (*)(int, void *))key_hook, &hrac_pozice); // Přidání NULL jako třetí argument
	mlx_loop(hrac_pozice.mlx_ptr);
}


