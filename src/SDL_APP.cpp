#include "../include/SDL_APP.hpp"
#include <SDL2/SDL_image.h>
#include <functional>
#include <iostream>

SDL_APP::SDL_APP(std::string title, int x, int y, int w, int h)
{
    m_window = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_gameIsRunning = true;

    // initializing SDL Video
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL not initialized" << SDL_GetError();
    } else if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("SDL image not working");
    } else {
        std::cout << "SDL video system is ready to go\n";
    }
}

SDL_APP::~SDL_APP()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void SDL_APP::EventCallBack(std::function<void(void)> function)
{
    m_EventCallBack = function;
}

void SDL_APP::RenderCallBack(std::function<void(void)> function)
{
    m_RenderCallBack = function;
}

void SDL_APP::SetGameIsRunning(bool b)
{
    m_gameIsRunning = b;
}

bool SDL_APP::GetGameIsRunning()
{
    return m_gameIsRunning;
}

SDL_Renderer *SDL_APP::GetRenderer() const
{
    return m_renderer;
}

SDL_Window *SDL_APP::GetWindow()
{
    return m_window;
}

void SDL_APP::RunLoop()
{
    while (m_gameIsRunning) {
        m_EventCallBack();
        m_RenderCallBack();
    }
}
