#include "window.h"

Window::Window(const std::string &title, int width, int height): 
title(title), width(width), height(height), window(nullptr), renderer(nullptr) {
    // criar janela (titulo, posicaoQueAJanelaVaiAbrirX, posicaoQueAJanelaVaiAbrirY,
    // larguraJanela, alturaJanela, flags)
    window = SDL_CreateWindow(title.c_str(), 
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // SDL_WINDOWPOS_UNDEFINED vai centralizar
    width, height, 
    SDL_WINDOW_SHOWN);// SDL_WINDOW_SHOWN flag para exibir imediatamente

    // Verifica se ocorreu um erro ao criar a janela e se sim encerra o sdl
    if(window == nullptr) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    // Cria renderizador para a janela
    // SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags);
    renderer = SDL_CreateRenderer(window, //ponteiro para a janela, este é o alvo da renderização. 
    -1, //Índice especifica o driver renderização, caso haja vários disponíveis. -1 = usar o primeiro driver compatível encontrado. -1 = escolha segura.    
    SDL_RENDERER_ACCELERATED); //tags que controlam o render. SDL_RENDERER_ACCELERATED: Use aceleração por hardware, se disponível.

    // Verifica se ocorreu um erro ao criar o renderer e se sim encerra o sdl
    if (renderer == nullptr) {
        printf("Erro ao criar o renderizador: %s\n", SDL_GetError());
        SDL_Quit();
        SDL_DestroyWindow(window);
        exit(1);
    }
}

Window::~Window() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}

int Window::getHeight() {
    return height;
}

int Window::getWidth() {
    return width;
}