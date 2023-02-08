#include "../include/Position.hpp"
#include "../include/Bishop.hpp"
#include "../include/King.hpp"
#include "../include/Knight.hpp"
#include "../include/Pawn.hpp"
#include "../include/Piece.hpp"
#include "../include/Queen.hpp"
#include "../include/Rook.hpp"
#include <iostream>
#include <list>

// "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

Position::Position(SDL_Renderer *renderer, std::string s)
{

    int blackRookCount = 0, blackPawnCount = 0, blackBishopCount = 0, blackKnightCount = 0;

    int whiteRookCount = 0, whitePawnCount = 0, whiteBishopCount = 0, whiteKnightCount = 0;

    int x = 0, y = 0;

    for (auto &c : s) {
        switch (c) {
        case '/':
        {
            y += 80;
            x = 0;
            break;
        }
        case '1':
        {
            x += 80;
            break;
        }
        case '2':
        {
            x += 2 * 80;
            break;
        }
        case '3':
        {
            x += 3 * 80;
            break;
        }
        case '4':
        {
            x += 4 * 80;
            break;
        }
        case '5':
        {
            x += 5 * 80;
            break;
        }
        case '6':
        {
            x += 6 * 80;
            break;
        }
        case '7':
        {
            x += 7 * 80;
            break;
        }
        case '8':
        {
            x += 8 * 80;
            break;
        }
        case 'p':
        {
            switch (blackPawnCount) {
            case 0:
            {
                blackPawnCount++;
                Pawn *blackPawn1 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn1->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn1);
                x += 80;
                break;
            }
            case 1:
            {
                blackPawnCount++;
                Pawn *blackPawn2 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn2->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn2);
                x += 80;
                break;
            }
            case 2:
            {
                blackPawnCount++;
                Pawn *blackPawn3 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn3->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn3);
                x += 80;
                break;
            }
            case 3:
            {
                blackPawnCount++;
                Pawn *blackPawn4 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn4->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn4);
                x += 80;
                break;
            }
            case 4:
            {
                blackPawnCount++;
                Pawn *blackPawn5 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn5->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn5);
                x += 80;
                break;
            }
            case 5:
            {
                blackPawnCount++;
                Pawn *blackPawn6 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn6->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn6);
                x += 80;
                break;
            }
            case 6:
            {
                blackPawnCount++;
                Pawn *blackPawn7 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn7->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn7);
                x += 80;
                break;
            }
            case 7:
            {
                blackPawnCount++;
                Pawn *blackPawn8 = new Pawn(false, renderer, "./assets/images/128pxPieces/b_pawn_png_shadow_128px.png");
                blackPawn8->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(blackPawn8);
                x += 80;
                break;
            }
            }
            break;
        }
        case 'P':
        {
            switch (whitePawnCount) {
            case 0:
            {
                whitePawnCount++;
                Pawn *whitePawn1 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn1->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn1);
                x += 80;
                break;
            }
            case 1:
            {
                whitePawnCount++;
                Pawn *whitePawn2 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn2->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn2);
                x += 80;
                break;
            }
            case 2:
            {
                whitePawnCount++;
                Pawn *whitePawn3 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn3->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn3);
                x += 80;
                break;
            }
            case 3:
            {
                whitePawnCount++;
                Pawn *whitePawn4 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn4->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn4);
                x += 80;
                break;
            }
            case 4:
            {
                whitePawnCount++;
                Pawn *whitePawn5 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn5->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn5);
                x += 80;
                break;
            }
            case 5:
            {
                whitePawnCount++;
                Pawn *whitePawn6 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn6->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn6);
                x += 80;
                break;
            }
            case 6:
            {
                whitePawnCount++;
                Pawn *whitePawn7 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn7->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn7);
                x += 80;
                break;
            }
            case 7:
            {
                whitePawnCount++;
                Pawn *whitePawn8 = new Pawn(true, renderer, "./assets/images/128pxPieces/w_pawn_png_shadow_128px.png");
                whitePawn8->GetTexturedRectangle().SetPosition(x, y);
                piecesInPlay.push_back(whitePawn8);
                x += 80;
                break;
            }
            }
            break;
        }
        case 'k':
        {
            King *blackKing = new King(false, renderer, "./assets/images/128pxPieces/b_king_png_shadow_128px.png");
            blackKing->GetTexturedRectangle().SetPosition(x, y);
            piecesInPlay.push_back(blackKing);
            x += 80;
            break;
        }
        case 'K':
        {
            King *whiteKing = new King(true, renderer, "./assets/images/128pxPieces/w_king_png_shadow_128px.png");
            whiteKing->GetTexturedRectangle().SetPosition(x, y);
            piecesInPlay.push_back(whiteKing);
            x += 80;
            break;
        }
        case 'q':
        {
            Queen *blackQueen = new Queen(false, renderer, "./assets/images/128pxPieces/b_queen_png_shadow_128px.png");
            blackQueen->GetTexturedRectangle().SetPosition(x, y);
            piecesInPlay.push_back(blackQueen);
            x += 80;
            break;
        }
        case 'Q':
        {
            Queen *whiteQueen = new Queen(false, renderer, "./assets/images/128pxPieces/w_queen_png_shadow_128px.png");
            whiteQueen->GetTexturedRectangle().SetPosition(x, y);
            piecesInPlay.push_back(whiteQueen);
            x += 80;
            break;
        }
        case 'n':
        {
            switch (blackKnightCount) {
            case 0:
            {
                Knight *blackKnight1 = new Knight(false, renderer, "./assets/images/128pxPieces/b_knight_png_shadow_128px.png");
                blackKnight1->GetTexturedRectangle().SetPosition(x, y);
                blackKnightCount++;
                piecesInPlay.push_back(blackKnight1);
                x += 80;
                break;
            }
            case 1:
            {
                Knight *blackKnight2 = new Knight(false, renderer, "./assets/images/128pxPieces/b_knight_png_shadow_128px.png");
                blackKnight2->GetTexturedRectangle().SetPosition(x, y);
                blackKnightCount++;
                piecesInPlay.push_back(blackKnight2);
                x += 80;
                break;
            }
            }
            break;
        }
        case 'N':
        {
            switch (whiteKnightCount) {
            case 0:
            {
                Knight *whiteKnight1 = new Knight(true, renderer, "./assets/images/128pxPieces/w_knight_png_shadow_128px.png");
                whiteKnight1->GetTexturedRectangle().SetPosition(x, y);
                whiteKnightCount++;
                piecesInPlay.push_back(whiteKnight1);
                x += 80;
                break;
            }
            case 1:
            {
                Knight *whiteKnight2 = new Knight(true, renderer, "./assets/images/128pxPieces/w_knight_png_shadow_128px.png");
                whiteKnight2->GetTexturedRectangle().SetPosition(x, y);
                whiteKnightCount++;
                piecesInPlay.push_back(whiteKnight2);
                x += 80;
                break;
            }
            }
            break;
        }
        case 'r':
        {
            switch (blackRookCount) {
            case 0:
            {
                Rook *blackRook1 = new Rook(false, renderer, "./assets/images/128pxPieces/b_rook_png_shadow_128px.png");
                blackRook1->GetTexturedRectangle().SetPosition(x, y);
                blackRookCount++;
                piecesInPlay.push_back(blackRook1);
                x += 80;
                break;
            }
            case 1:
            {
                Rook *blackRook2 = new Rook(false, renderer, "./assets/images/128pxPieces/b_rook_png_shadow_128px.png");
                blackRook2->GetTexturedRectangle().SetPosition(x, y);
                blackRookCount++;
                piecesInPlay.push_back(blackRook2);
                x += 80;
                break;
            }
            }
            break;
        }
        case 'R':
        {
            switch (whiteRookCount) {
            case 0:
            {
                Rook *whiteRook1 = new Rook(true, renderer, "./assets/images/128pxPieces/w_rook_png_shadow_128px.png");
                whiteRook1->GetTexturedRectangle().SetPosition(x, y);
                whiteRookCount++;
                piecesInPlay.push_back(whiteRook1);
                x += 80;
                break;
            }
            case 1:
            {
                Rook *whiteRook2 = new Rook(true, renderer, "./assets/images/128pxPieces/w_rook_png_shadow_128px.png");
                whiteRook2->GetTexturedRectangle().SetPosition(x, y);
                whiteRookCount++;
                piecesInPlay.push_back(whiteRook2);
                x += 80;
                break;
            }
            }
            break;
        }
        case 'b':
        {
            switch (blackBishopCount) {
            case 0:
            {
                Bishop *blackBishop1 = new Bishop(false, renderer, "./assets/images/128pxPieces/b_bishop_png_shadow_128px.png");
                blackBishop1->GetTexturedRectangle().SetPosition(x, y);
                blackBishopCount++;
                piecesInPlay.push_back(blackBishop1);
                x += 80;
                break;
            }
            case 1:
            {
                Bishop *blackBishop2 = new Bishop(false, renderer, "./assets/images/128pxPieces/b_bishop_png_shadow_128px.png");
                blackBishop2->GetTexturedRectangle().SetPosition(x, y);
                blackBishopCount++;
                piecesInPlay.push_back(blackBishop2);
                x += 80;
                break;
            }
            }
            break;
        }
        case 'B':
        {
            switch (whiteBishopCount) {
            case 0:
            {
                Bishop *whiteBishop1 = new Bishop(true, renderer, "./assets/images/128pxPieces/w_bishop_png_shadow_128px.png");
                whiteBishop1->GetTexturedRectangle().SetPosition(x, y);
                whiteBishopCount++;
                piecesInPlay.push_back(whiteBishop1);
                x += 80;
                break;
            }
            case 1:
            {
                Bishop *whiteBishop2 = new Bishop(true, renderer, "./assets/images/128pxPieces/w_bishop_png_shadow_128px.png");
                whiteBishop2->GetTexturedRectangle().SetPosition(x, y);
                whiteBishopCount++;
                piecesInPlay.push_back(whiteBishop2);
                x += 80;
                break;
            }
            }
            break;
        }
        }
    }
}

std::list<Piece *> Position::GetPiecesInPlay()
{
    return piecesInPlay;
}
