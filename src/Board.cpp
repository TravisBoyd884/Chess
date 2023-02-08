#include "../include/Board.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <iostream>

using std::string;

void Board::RenderBoard(SDL_Renderer *renderer)
{
    SDL_Rect rect;
    rect.h = 80;
    rect.w = 80;
    rect.x = 0;
    rect.y = 0;

    for (int row = 0; row < 8; row++, rect.y += 80) {
        for (int col = 0; col < 8; col++, rect.x += 80) {
            // alternates render draw color between black and white
            if ((row + col) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            }

            SDL_RenderFillRect(renderer, &rect);
        }
        rect.x = 0;
    }
}
