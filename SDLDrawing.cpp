#include "SDLDrawing.h"
#include <iostream>
#include <thread>

// Variable globale indiquant si les fenêtres doivent continuer à s'exécuter
bool running = true;


void SDLDrawing::DrawWindow(const char* title, PixelGrid table, void (SDLDrawing::*drawFunction)(SDL_Renderer*, int**, int, int, PixelGrid)) {
    SDL_Window* window = SDL_CreateWindow(title, 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        table.get_width() * 7, table.get_height() * 7, 0);

    if (!window) {
        std::cerr << "Erreur lors de la création de la fenêtre: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int** letterGrid = table.get_grid();
    for (int i = 0; i < table.get_height(); i++) {
        for (int j = 0; j < table.get_width(); j++) {
            (this->*drawFunction)(renderer, letterGrid, j, i, table);
        }
    }

    SDL_RenderPresent(renderer);

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // Arrêt global si la croix est cliquée
            }
            if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_q)) {
                running = false; // Arrêt global si  'q' est pressé
            }
        }
        SDL_Delay(16); // Limite la charge CPU
        if (!running) break;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void SDLDrawing::EmptyLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table) {
    if (letterGrid[j][i] == 2) {
        SDL_Rect srcrect = { i * 5, table.get_height() / 2 + j * 5, 5, 5 };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &srcrect);
    }
}

void SDLDrawing::SolidBlackLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table) {
    if (letterGrid[j][i] == 1 || letterGrid[j][i] == 2) {
        SDL_Rect srcrect = { i * 5, table.get_height() / 2 + j * 5, 5, 5 };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &srcrect);
    }
}

void SDLDrawing::RedLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table) {
    if (letterGrid[j][i] == 1) {
        SDL_Rect srcrect = { i * 5, table.get_height() / 2 + j * 5, 5, 5 };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &srcrect);
    }
    if (letterGrid[j][i] == 2) {
        SDL_Rect srcrect = { i * 5, table.get_height() / 2 + j * 5, 5, 5 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &srcrect);
    }
}

void SDLDrawing::Draw(int x, int width, int height) {
    PixelGrid table(width, height);
    LetterSelector::selectLetter(table, x);
    std::cout << "En cours..." << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Échec de l'initialisation de SDL" << std::endl;
    }

    std::thread emptyThread(&SDLDrawing::DrawWindow, this, "Police Vide", table, &SDLDrawing::EmptyLetter);
    std::thread solidThread(&SDLDrawing::DrawWindow, this, "Police Noire", table, &SDLDrawing::SolidBlackLetter);
    std::thread redThread(&SDLDrawing::DrawWindow, this, "Police Rouge", table, &SDLDrawing::RedLetter);

    emptyThread.join();
    solidThread.join();
    redThread.join();

    std::cout << "Toutes les fenêtres ont été fermées." << std::endl;

    SDL_Quit();
}

void SDLDrawing::Draw2(int width, int height) {
    PixelGrid table(width, height);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Window* window = SDL_CreateWindow("All letters",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          table.get_width() * 7, table.get_height() * 7,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    // Create SDL renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Main loop variables
    bool running = true;
    SDL_Event event;
    Uint32 lastTime = SDL_GetTicks(); // Time of the last action
    const int intervalMs = 500;      // time interval

    char letter =  'A';
    int count = 0;
    
        
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // Arrêt global si la croix est cliquée
            }
            if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_q)) {
                running = false; // Arrêt global si  'q' est pressé
            }
        }

        // Get the current time
        Uint32 currentTime = SDL_GetTicks();

        if (currentTime > lastTime + intervalMs) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            lastTime = currentTime;
            LetterSelector::selectLetter(table, letter);
            int** letterGrid = table.get_grid();
            for (int i = 0; i < table.get_height(); i++) {
                for (int j = 0; j < table.get_width(); j++) {
                    if(count == 0)
                        EmptyLetter(renderer, letterGrid, j, i, table);
                    else if(count == 1) 
                        SolidBlackLetter(renderer, letterGrid, j, i, table);
                    else
                        RedLetter(renderer, letterGrid, j, i, table);
                    table.set_pixel(j, i, 0);///to reset the table for next iteration
                }
            }
            count++;
            if(count == 3){
                if(letter == 'Z')
                    letter = 'A';
                else
                    letter++;
                count = 0;
            }
            SDL_RenderPresent(renderer);
        }

        // Update the screen
        SDL_RenderPresent(renderer);

        // Frame rate limiting
        SDL_Delay(16); // ~60 FPS
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}