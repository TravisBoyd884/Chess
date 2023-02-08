#include "../include/Pawn.hpp"
#include "../include/Piece.hpp"

Pawn::Pawn(bool white, SDL_Renderer *renderer, std::string spritepath) : super(white, renderer, spritepath)
{
}

Pawn::~Pawn()
{
}
