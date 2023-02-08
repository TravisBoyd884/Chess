#include "../include/ResourceManager.hpp"
#include <SDL2/SDL_image.h>

ResourceManager::ResourceManager()
{
}
ResourceManager::ResourceManager(ResourceManager const &)
{
}

ResourceManager ResourceManager::operator=(ResourceManager const &rhs)
{
    // to do
    return *this;
}

ResourceManager &ResourceManager::GetInstance()
{
    static ResourceManager *s_instance = new ResourceManager();
    return *s_instance;
}

SDL_Surface *ResourceManager::GetSurface(std::string filepath)
{
    // look through m_surfaces(unordered map) and see if a file exists
    // if the file does exists, then return associated surface

    auto search = m_surfaces.find(filepath);
    if (search != m_surfaces.end()) {
        return m_surfaces[filepath];
    } else {
        SDL_Surface *surface = IMG_Load(filepath.c_str());
        m_surfaces.insert(std::make_pair(filepath, surface));
        return m_surfaces[filepath];
    }

    return nullptr;
}
