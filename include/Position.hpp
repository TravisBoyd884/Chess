#include "../include/Pawn.hpp"
#include "../include/Piece.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <list>

class Position
{
  public:
    Position(SDL_Renderer *renderer, std::string);
    std::list<Piece *> GetPiecesInPlay();
    ~Position();

  private:
    std::list<Piece *> piecesInPlay;
};
