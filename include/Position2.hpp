#pragma once
#include "../include/Bishop.hpp"
#include "../include/King.hpp"
#include "../include/Knight.hpp"
#include "../include/Pawn.hpp"
#include "../include/Piece.hpp"
#include "../include/Queen.hpp"
#include "../include/Rook.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <list>

class Position2
{
  public:
    Position2(SDL_Renderer *renderer, std::string s);
    std::list<Piece *> GetPiecesInPlay();
    ~Position2();

  private:
    std::list<Piece *> m_piecesInPlay;
    Pawn *m_whitePawns[8];
    Pawn *m_blackPawns[8];
    Bishop *m_whiteBishops[8];
    Bishop *m_blackBishops[8];
    Rook *m_whiteRooks[8];
    Rook *m_blackRooks[8];
    Knight *m_whiteKnights[8];
    Knight *m_blackKnights[8];
};
