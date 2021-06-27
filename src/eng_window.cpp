#include "eng_window.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include <iostream>

namespace eng {

EngWindow::EngWindow(int w, int h, std::string name) : WIDTH{w}, HEIGHT{h}, windowName{name} {
    initWindow();
    initRenderer();
}

void EngWindow::initWindow() {
  window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, HEIGHT, WIDTH, SDL_WINDOW_SHOWN);

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

void EngWindow::clear()
{
    SDL_RenderClear(renderer);
}

void EngWindow::render(SDL_Texture* tex)
{
    SDL_RenderCopy(renderer, tex, nullptr, nullptr);
}

void EngWindow::display()
{
    SDL_RenderPresent(renderer);
}

} // namespace eng