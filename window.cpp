#include "window.h"

// Construtor da classe Window, inicializa uma janela SDL e um renderizador
Window::Window(const std::string &title, double width, double height)
    : title(title), width(width), height(height), window(nullptr), renderer(nullptr) {
    // Cria a janela com título, posição indefinida (centralizada), largura, altura e a flag para exibir imediatamente
    window = SDL_CreateWindow(title.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // SDL_WINDOWPOS_UNDEFINED vai centralizar
        width, height, 
        SDL_WINDOW_SHOWN); // SDL_WINDOW_SHOWN flag para exibir imediatamente

    // Verifica se ocorreu um erro ao criar a janela e, se sim, encerra o SDL
    if (window == nullptr) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    // Cria o renderizador para a janela
    renderer = SDL_CreateRenderer(window, // Ponteiro para a janela, este é o alvo da renderização
        -1, // Índice especifica o driver de renderização, -1 = usar o primeiro driver compatível encontrado
        SDL_RENDERER_ACCELERATED); // SDL_RENDERER_ACCELERATED: Use aceleração por hardware, se disponível

    // Verifica se ocorreu um erro ao criar o renderizador e, se sim, encerra o SDL e destrói a janela
    if (renderer == nullptr) {
        printf("Erro ao criar o renderizador: %s\n", SDL_GetError());
        SDL_Quit();
        SDL_DestroyWindow(window);
        exit(1);
    }
}

// Destrutor da classe Window, garante a liberação dos recursos alocados
Window::~Window() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

// Retorna o ponteiro para o renderizador SDL
SDL_Renderer* Window::getRenderer() const {
    return renderer;
}

// Retorna a altura da janela
double Window::getHeight() const {
    return height;
}

// Retorna a largura da janela
double Window::getWidth() const {
    return width;
}
