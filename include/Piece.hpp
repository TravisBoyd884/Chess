#pragma once
#include "GameEntity.hpp"
class Piece : public GameEntity
{
  public:
    Piece(bool white, SDL_Renderer *renderer, std::string spritepath);
    typedef GameEntity super;
    bool IsWhite();
    bool IsKilled();
    bool SetKilled();
    ~Piece();

  private:
    bool m_killed = false;
    bool m_isWhite = false;
};
