#pragma once
#include "../include/Piece.hpp"
class Knight : public Piece
{
  public:
    Knight();
    Knight(bool white, SDL_Renderer *renderer, std::string spritepath);
    typedef Piece super;
    void SetColor(bool color);
    ~Knight();

  private:
};
