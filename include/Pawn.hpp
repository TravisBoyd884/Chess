#pragma once
#include "../include/Piece.hpp"
#include <iostream>

class Pawn : public Piece
{
  public:
    Pawn();
    Pawn(bool white, SDL_Renderer *renderer, std::string spritepath);
    typedef Piece super;
    void SetColor(bool color);
    ~Pawn();

  private:
    std::string m_imagepath;
};
