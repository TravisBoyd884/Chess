#include "../include/Piece.hpp"
#include <SDL2/SDL_render.h>

Piece::Piece(bool white, SDL_Renderer *renderer, std::string spritepath) : super(renderer, spritepath)
{
    m_isWhite = true;
}

Piece::~Piece()
{
}

bool Piece::IsWhite()
{
    return m_isWhite;
}

bool Piece::IsKilled()
{
    return m_killed;
}

bool Piece::SetKilled()
{
    return m_killed;
}
