#pragma once
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <unordered_map>

class ResourceManager
{
  private:
    ResourceManager();
    ResourceManager(ResourceManager const &);
    ResourceManager operator=(ResourceManager const &);

    std::unordered_map<std::string, SDL_Surface *> m_surfaces;

  public:
    static ResourceManager &GetInstance();
    SDL_Surface *GetSurface(std::string filepath);
};
