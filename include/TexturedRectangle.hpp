#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <iterator>

class TexturedRectangle
{
  public:
    TexturedRectangle(SDL_Renderer *&renderer, std::string filepath);
    void SetRectangleProperties(int x, int y, int w, int h);
    void SetPosition(int x, int y);
    bool IsColliding(SDL_Rect &rect);
    SDL_Rect *GetRectangle();
    void Render(SDL_Renderer *&renderer);

    ~TexturedRectangle();

  private:
    SDL_Texture *m_texture;
    SDL_Renderer *m_renderer;
    SDL_Rect m_rectangle;
};
