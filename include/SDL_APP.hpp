#pragma once
#include <SDL2/SDL.h>
#include <functional>
#include <iostream>

class SDL_APP
{
  public:
    SDL_APP(std::string title, int x, int y, int w, int h);
    void EventCallBack(std::function<void(void)> function);
    void RenderCallBack(std::function<void(void)> function);
    void SetGameIsRunning(bool b);
    bool GetGameIsRunning();
    SDL_Renderer *GetRenderer() const;
    SDL_Window *GetWindow();
    void RunLoop();
    ~SDL_APP();

  private:
    bool m_gameIsRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    std::function<void(void)> m_EventCallBack;
    std::function<void(void)> m_RenderCallBack;
};
