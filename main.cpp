/*!
 * @file main.cpp
 * @author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#include <iostream>
#include "SDLDrawing.h"

/**
 * @brief Fonction principale représentant le point d'entrée de l'application SDL.
 * 
 * Cette fonction initialise l'objet SDLDrawing, crée une fenêtre SDL, dessine une lettre 
 * dans trois fenêtres différentes de manière simultanée grâce aux threads et gère le flux
 * de l'application.
 * 
 * @param argc Nombre d'arguments en ligne de commande.
 * @param argv Tableau des arguments en ligne de commande.
 * @return Entier indiquant le statut de sortie de l'application.
 */
int SDL_main(int argc, char* argv[]) {
    try {
        // Create an SDLDrawing object
        SDLDrawing lettreSDL;

        // Create a PixelGrid for the letter 'Q' with specified dimensions
        PixelGrid table = lettreSDL.Window('Q', 40, 50);
        if (table.get_width() == 0 || table.get_height() == 0) {
            std::cerr << "Erreur lors de la création du PixelGrid" << std::endl;
            return 1;
        }

        // Draw the letter in three separate windows using threads
        lettreSDL.Draw(table);

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Une erreur est survenue : " << e.what() << std::endl;
        return 1;
    }
}