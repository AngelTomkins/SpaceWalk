#include "eng_window.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include <iostream>

namespace eng {

void EngWindow::init(int w, int h, std::string name)
{
    WIDTH = w;
    HEIGHT = h;
    windowName = name;

    initWindow();
    initRenderer();
}

void EngWindow::initWindow() {
  window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  
}

void EngWindow::closeWindow() {
    SDL_DestroyWindow(window);
}

void EngWindow::initRenderer(){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* EngWindow::loadTexture(const char* filePath)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

int EngWindow::getRefershRate()
{
  int displayIndex = SDL_GetWindowDisplayIndex(window);

  SDL_DisplayMode mode;

  SDL_GetDisplayMode(displayIndex, 0, &mode);
  return mode.refresh_rate;
}

void EngWindow::clear()
{
    SDL_RenderClear(renderer);
}

void EngWindow::render(EngEntity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPos().x * constants::scale;
    dst.y = p_entity.getPos().y * constants::scale;
    dst.w = p_entity.getCurrentFrame().w * constants::scale;
    dst.h = p_entity.getCurrentFrame().h * constants::scale;


    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void EngWindow::display()
{
    SDL_RenderPresent(renderer);
}
} // namespace eng