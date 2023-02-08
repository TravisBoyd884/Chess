#pragma once
#include "./TexturedRectangle.hpp"
#include <SDL2/SDL.h>

class GameEntity
{
  public:
    GameEntity()
    {
        m_sprite = nullptr;
    }

    GameEntity(SDL_Renderer *renderer, std::string spritepath)
    {
        m_renderer = renderer;
        m_sprite = new TexturedRectangle(m_renderer, spritepath);
    }

    void Draw()
    {
    }

    void Update()
    {
    }

    void Render()
    {
        if (nullptr != m_sprite) {
            m_sprite->Render(m_renderer);
        }
    }

    TexturedRectangle &GetTexturedRectangle()
    {
        return *m_sprite;
    }

    ~GameEntity()
    {
    }

  private:
    TexturedRectangle *m_sprite;
    SDL_Renderer *m_renderer;
};
