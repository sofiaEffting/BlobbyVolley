#include "text.h"

Text::Text(const std::string &text, SDL_Renderer* renderer, std::string fontPath, SDL_Color textColor, int fontSize,
    double width, double height, double x, double y) 
    : text(text), renderer(renderer), textColor(textColor), fontSize(fontSize), width(width), height(height), x(x), y(y)  {
    if (TTF_Init() == -1) {
        std::cerr << "Erro ao inicializar o SDL_ttf: " << TTF_GetError() << std::endl;
    }
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        std::cerr << "Erro ao carregar a fonte: " << TTF_GetError() << std::endl;
    }
    // Renderização do texto
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        SDL_DestroyTexture(texture);
        std::cerr << "Erro ao criar textura " << TTF_GetError() << std::endl;
    }
}

Text::~Text() {
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
    TTF_Quit();
}

void Text::draw() {
    // Define a posição e tamanho do texto na janela
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.h = height;
    r.w = width;
    // Renderiza a textura do texto no renderer
    SDL_RenderCopy(renderer, texture, NULL, (const SDL_Rect*)&r);
}

std::ostream &operator<<(std::ostream &os, const Text &text) {
    os << text.text << text.x << text.y;
    return os;
}

// Getter para fontSize
int Text::getFontSize() const {
    return fontSize;
}

// Setter para fontSize
void Text::setFontSize(int fontSize) {
    fontSize = fontSize;
}

// Getter para width
double Text::getWidth() const {
    return width;
}

// Setter para width
void Text::setWidth(double w) {
    width = w;
}

// Getter para height
double Text::getHeight() const {
    return height;
}

// Setter para height
void Text::setHeight(double h) {
    height = h;
}

// Getter para x
double Text::getX() const {
    return x;
}

// Setter para x
void Text::setX(double x) {
    x = x;
}

// Getter para y
double Text::getY() const {
    return y;
}

// Setter para y
void Text::setY(double y) {
    Text::y = y;
}

void Text::updateText(const int p1Points, const int p2Points) {
    text = std::to_string(p1Points) + " X " + std::to_string(p2Points);

    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        SDL_DestroyTexture(texture);
        std::cerr << "Erro ao criar textura " << TTF_GetError() << std::endl;
    }
}
