#pragma once
#include "../include/Piece.hpp"
class Bishop : public Piece
{
  public:
    Bishop();
    Bishop(bool white, SDL_Renderer *renderer, std::string spritepath);
    typedef Piece super;
    void SetColor(bool color);
    ~Bishop();

  private:
};
