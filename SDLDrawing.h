/**
 * @file SDLDrawing.h
 * @author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#ifndef SDL_DRAWING_H
#define SDL_DRAWING_H

#include <SDL.h>
#include "PixelGrid.h"
#include "LetterSelector.h"

/**
 * @class SDLDrawing
 * @brief Fournit des fonctionnalités pour dessiner sur une fenêtre SDL en utilisant un objet PixelGrid.
 */
class SDLDrawing {

private:
    /**
     * @brief Dessine une fenêtre spécifique avec la police sélectionnée.
     * @param title Titre de la fenêtre.
     * @param table Objet PixelGrid à utiliser pour le dessin.
     * @param drawFunction Pointeur vers la fonction de dessin à utiliser.
     */
    void DrawWindow(const char* title, PixelGrid table, void (SDLDrawing::*drawFunction)(SDL_Renderer*, int**, int, int, PixelGrid));

    /**
     * @brief Dessine une lettre vide sur la fenêtre SDL à la position spécifiée.
     * @param renderer Le renderer SDL utilisé pour le dessin.
     * @param letterGrid Tableau 2D représentant le PixelGrid de la lettre.
     * @param j Coordonnée X de la position de départ.
     * @param i Coordonnée Y de la position de départ.
     * @param table Objet PixelGrid sur lequel dessiner la lettre.
     */
    void EmptyLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table);

    /**
     * @brief Dessine une lettre noire solide sur la fenêtre SDL à la position spécifiée.
     * @param renderer Le renderer SDL utilisé pour le dessin.
     * @param letterGrid Tableau 2D représentant le PixelGrid de la lettre.
     * @param j Coordonnée X de la position de départ.
     * @param i Coordonnée Y de la position de départ.
     * @param table Objet PixelGrid sur lequel dessiner la lettre.
     */
    void SolidBlackLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table);

    /**
     * @brief Dessine une lettre rouge sur la fenêtre SDL à la position spécifiée.
     * @param renderer Le renderer SDL utilisé pour le dessin.
     * @param letterGrid Tableau 2D représentant le PixelGrid de la lettre.
     * @param j Coordonnée X de la position de départ.
     * @param i Coordonnée Y de la position de départ.
     * @param table Objet PixelGrid sur lequel dessiner la lettre.
     */
    void RedLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table);

public:
    /**
     * @brief Crée une fenêtre SDL et retourne un objet PixelGrid associé.
     * @param x Coordonnée X de la fenêtre.
     * @param width Largeur de la fenêtre.
     * @param height Hauteur de la fenêtre.
     * @return Objet PixelGrid représentant la fenêtre SDL.
     */
    PixelGrid Window(int x, int width, int height);

    /**
     * @brief Dessine le contenu du PixelGrid donné sur trois fenêtres SDL distinctes en parallèle.
     * @param table Objet PixelGrid à dessiner sur les fenêtres SDL.
     */
    void Draw(PixelGrid table);
};

#endif // SDL_DRAWING_H