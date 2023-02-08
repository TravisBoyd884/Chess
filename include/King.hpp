#pragma once
#include "../include/Piece.hpp"
class King : public Piece
{
  public:
    King(bool white, SDL_Renderer *renderer, std::string spritepath);

    typedef Piece super;
    void SetColor(bool color);
    ~King();

  private:
};
