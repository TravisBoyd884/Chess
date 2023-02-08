#include "../include/Position2.hpp"
#include <SDL2/SDL.h>
#include <ctype.h>
#include <iostream>
#include <list>

Position2::Position2(SDL_Renderer *renderer, std::string s)
{
    int blackRookCount = 0, blackPawnCount = 0, blackBishopCount = 0, blackKnightCount = 0;

    int whiteRookCount = 0, whitePawnCount = 0, whiteBishopCount = 0, whiteKnightCount = 0;

    int x = 0, y = 0;

    for (auto &c : s) {
        if (isdigit(c)) {
            int num = (int)c;
            x += num * 80;
            continue;
        } else if (c == '/') {
            y += 80;
            x = 0;
            continue;
        }

        switch (c) {
        case 'p':
        {
            m_blackPawns[blackPawnCount] = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
            m_blackPawns[blackPawnCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_blackPawns[blackPawnCount]);
            blackPawnCount++;
            break;
        }
        case 'P':
        {
            m_whitePawns[whitePawnCount] = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
            m_whitePawns[whitePawnCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_whitePawns[whitePawnCount]);
            whitePawnCount++;
            break;
        }
        case 'k':
        {
            King *blackKing = new King(true, renderer, "./assets/images/128pxPieces/b_king_png_shadow_128px.png");
            blackKing->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(blackKing);
            break;
        }
        case 'K':
        {
            King *whiteKing = new King(true, renderer, "./assets/images/128pxPieces/w_king_png_shadow_128px.png");
            whiteKing->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(whiteKing);
            break;
        }
        case 'q':
        {
            Queen *blackQueen = new Queen(true, renderer, "./assets/images/128pxPieces/b_queen_png_shadow_128px.png");
            blackQueen->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(blackQueen);
            break;
        }
        case 'Q':
        {
            Queen *whiteQueen = new Queen(true, renderer, "./assets/images/128pxPieces/w_queen_png_shadow_128px.png");
            whiteQueen->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(whiteQueen);
            break;
        }
        case 'r':
        {
            m_blackRooks[blackRookCount] = new Rook(false, renderer, "./assets/images/128pxPieces/b_rook_png_shadow_128px.png");
            m_blackRooks[blackRookCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_blackRooks[blackRookCount]);
            blackRookCount++;
            break;
        }
        case 'R':
        {
            m_whiteRooks[whiteRookCount] = new Rook(true, renderer, "./assets/images/128pxPieces/w_rook_png_shadow_128px.png");
            m_whiteRooks[whiteRookCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_whiteRooks[whiteRookCount]);
            whiteRookCount++;
            break;
        }
        case 'n':
        {
            m_blackKnights[blackKnightCount] = new Knight(false, renderer, "./assets/images/128pxPieces/b_knight_png_shadow_128px.png");
            m_blackKnights[blackKnightCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_blackKnights[blackKnightCount]);
            blackKnightCount++;
            break;
        }
        case 'N':
        {
            m_whiteKnights[whiteKnightCount] = new Knight(true, renderer, "./assets/images/128pxPieces/w_knight_png_shadow_128px.png");
            m_whiteKnights[whiteKnightCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_whiteKnights[whiteKnightCount]);
            whiteKnightCount++;
            break;
        }
        case 'b':
        {
            m_blackBishops[blackBishopCount] = new Bishop(false, renderer, "./assets/images/128pxPieces/b_bishop_png_shadow_128px.png");
            m_blackBishops[blackBishopCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_blackBishops[blackBishopCount]);
            blackBishopCount++;
            break;
        }
        case 'B':
        {
            m_whiteBishops[whiteBishopCount] = new Bishop(true, renderer, "./assets/images/128pxPieces/w_bishop_png_shadow_128px.png");
            m_whiteBishops[whiteBishopCount]->GetTexturedRectangle().SetPosition(x, y);
            m_piecesInPlay.push_back(m_whiteBishops[whiteBishopCount]);
            whiteBishopCount++;
            break;
        }
        }

        x += 80;
    }
}

std::list<Piece *> Position2::GetPiecesInPlay()
{
    return m_piecesInPlay;
}

Position2::~Position2()
{
}
