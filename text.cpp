#include "text.h"

// Construtor da classe Text
Text::Text(const std::string &text, SDL_Renderer* renderer, std::string fontPath, SDL_Color textColor, int fontSize,
    double width, double height, double x, double y) 
    : text(text), renderer(renderer), textColor(textColor), fontSize(fontSize), width(width), height(height), x(x), y(y)  {
    
    // Inicializa o SDL_ttf e verifica erros
    if (TTF_Init() == -1) {
        std::cerr << "Erro ao inicializar o SDL_ttf: " << TTF_GetError() << std::endl;
    }

    // Abre a fonte no caminho especificado e verifica erros
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        std::cerr << "Erro ao carregar a fonte: " << TTF_GetError() << std::endl;
    }

    // Renderiza o texto em uma superfície
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);

    // Cria uma textura a partir da superfície
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    // Verifica erros na criação da textura
    if (!texture) {
        SDL_DestroyTexture(texture);
        std::cerr << "Erro ao criar textura " << TTF_GetError() << std::endl;
    }
}

// Destrutor da classe Text
Text::~Text() {
    TTF_CloseFont(font);  // Fecha a fonte
    SDL_DestroyTexture(texture);  // Destroi a textura
    TTF_Quit();  // Encerra o SDL_ttf
}

// Método para desenhar o texto na tela
void Text::draw() {
    SDL_Rect r;  // Define um retângulo SDL
    r.x = x;  // Posição x do texto
    r.y = y;  // Posição y do texto
    r.h = height;  // Altura do texto
    r.w = width;  // Largura do texto

    // Renderiza a textura do texto no renderer
    SDL_RenderCopy(renderer, texture, NULL, (const SDL_Rect*)&r);
}

// Sobrecarga do operador << para a classe Text
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

// Método para atualizar o texto com novos pontos
void Text::updateText(const int p1Points, const int p2Points) {
    text = std::to_string(p1Points) + " X " + std::to_string(p2Points);

    // Renderiza o novo texto em uma superfície
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);

    // Cria uma nova textura a partir da superfície
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Verifica erros na criação da nova textura
    if (!texture) {
        SDL_DestroyTexture(texture);
        std::cerr << "Erro ao criar textura " << TTF_GetError() << std::endl;
    }
}
