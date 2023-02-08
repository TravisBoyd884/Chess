#pragma once
#include "../include/Piece.hpp"
class Rook : public Piece
{
  public:
    Rook();
    Rook(bool white, SDL_Renderer *renderer, std::string spritepath);
    typedef Piece super;
    void SetColor(bool color);
    ~Rook();

  private:
};
