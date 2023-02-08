#include "../include/MainLoop.hpp"
#include "../include/Board.hpp"
#include "../include/GameEntity.hpp"
#include "../include/Pawn.hpp"
#include "../include/Piece.hpp"
#include "../include/Position.hpp"
#include "../include/Position2.hpp"
#include "../include/SDL_APP.hpp"
#include "../include/TexturedRectangle.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include <iostream>
#include <list>

SDL_APP *app;
std::list<Piece *> piecesInPlay;
bool startingPositionRendered = false;

void HandleRendering()
{

    SDL_RenderClear(app->GetRenderer());

    Board::RenderBoard(app->GetRenderer());
    for (auto Piece : piecesInPlay) {
        Piece->Render();
    }
    SDL_RenderPresent(app->GetRenderer());
}

void HandleEvents()
{
    SDL_Event event;
    bool leftMouseButtonDown = false;
    SDL_Point mousePos;
    SDL_Point finaleMousePos;
    SDL_Rect *selectedRect = nullptr;
    TexturedRectangle *selectedTexturedRectangle;
    SDL_Point clickOffset;
    Piece *selectedPiece;

    while (SDL_WaitEvent(&event) && app->GetGameIsRunning()) {

        switch (event.type) {
            // Press 0 to turn off game
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_0)
                app->SetGameIsRunning(false);
            break;

            // Handles mouse motion
        case SDL_MOUSEMOTION:
            mousePos = { event.motion.x, event.motion.y };

            // if the left mouse button is down and a rectangle is selected
            // player can drag the piece
            if (leftMouseButtonDown && selectedRect != NULL) {
                selectedRect->x = mousePos.x - clickOffset.x;
                selectedRect->y = mousePos.y - clickOffset.y;
            }
            break;
        case SDL_MOUSEBUTTONUP:

            // clicks the piece onto a square
            if (leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT) {
                leftMouseButtonDown = false;
                selectedRect->x = (mousePos.x / 80) * 80;
                selectedRect->y = (mousePos.y / 80) * 80;
                for (auto Piece : piecesInPlay) {
                    if (Piece->GetTexturedRectangle().IsColliding(*selectedRect) && Piece != selectedPiece) {
                        piecesInPlay.remove(Piece);
                        break;
                    }
                }
                selectedRect = NULL;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT) {
                leftMouseButtonDown = true;

                for (auto Piece : piecesInPlay) {
                    if (SDL_PointInRect(&mousePos, Piece->GetTexturedRectangle().GetRectangle())) {
                        selectedRect = Piece->GetTexturedRectangle().GetRectangle();
                        clickOffset.x = mousePos.x - selectedRect->x;
                        clickOffset.y = mousePos.y - selectedRect->y;
                        selectedPiece = Piece;
                        break;
                    }
                }
            }
            break;
        default:
            break;
        }
        HandleRendering();
    }
}

void Chess::MainLoop()
{
    app = new SDL_APP("Chess", 0, 0, 640, 640);
    // Position *position = new Position(app->GetRenderer(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    // piecesInPlay = position->GetPiecesInPlay();
    Position2 *position2 = new Position2(app->GetRenderer(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    piecesInPlay = position2->GetPiecesInPlay();
    app->EventCallBack(HandleEvents);
    app->RenderCallBack(HandleRendering);
    app->RunLoop();
}
