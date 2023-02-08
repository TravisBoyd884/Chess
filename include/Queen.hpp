#pragma once
#include "../include/Piece.hpp"
class Queen : public Piece
{
  public:
    Queen(bool white, SDL_Renderer *renderer, std::string spritepath);

    typedef Piece super;
    void SetColor(bool color);
    ~Queen();

  private:
};
