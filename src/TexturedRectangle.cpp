#include "../include/TexturedRectangle.hpp"
#include "../include/ResourceManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <iterator>

TexturedRectangle::TexturedRectangle(SDL_Renderer *&renderer, std::string filepath)
{
    SDL_Surface *retrieveSurface = ResourceManager::GetInstance().GetSurface(filepath);
    IMG_Init(IMG_INIT_PNG);

    // if (!surface) {
    //     std::cout << "Failed to Load Image" << std::endl;
    // }
    m_texture = SDL_CreateTextureFromSurface(renderer, retrieveSurface);

    m_rectangle.x = 80;
    m_rectangle.y = 80;
    m_rectangle.w = 80;
    m_rectangle.h = 80;
}

void TexturedRectangle::SetRectangleProperties(int x, int y, int w, int h)
{
    m_rectangle.x = x;
    m_rectangle.y = y;
    m_rectangle.w = w;
    m_rectangle.h = h;
}

void TexturedRectangle::SetPosition(int x, int y)
{
    m_rectangle.x = x;
    m_rectangle.y = y;
}

SDL_Rect *TexturedRectangle::GetRectangle()
{
    return &m_rectangle;
}

void TexturedRectangle::Render(SDL_Renderer *&renderer)
{
    SDL_RenderCopy(renderer, m_texture, NULL, &m_rectangle);
}

bool TexturedRectangle::IsColliding(SDL_Rect &rect)
{
    return SDL_HasIntersection(GetRectangle(), &rect);
}

TexturedRectangle::~TexturedRectangle()
{
    SDL_DestroyTexture(m_texture);
}
