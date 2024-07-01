CXX = g++   #compilador c++
CXXFLAGS = -Wall -I/usr/include/SDL # flags de compilação, -Wall (habilitar warnings), 
# -I/usr/include/SDL2 especifica onde encontrar os cabeçalhos da SDL2.
LIBS = -lSDL2 -lSDL2_ttf # Bibliotecas 
EXECUTABLES = main # oq vai ser chamado quando chamar só o make

# regra: dependências
#    comandos a serem executados para compilar o código
all: $(EXECUTABLES)

main: src/main.cpp src/circle.cpp src/rectangle.cpp src/window.cpp src/player.cpp src/vector.cpp src/ball.cpp src/game.cpp src/text.cpp
	$(CXX) $(CXXFLAGS) -o volley.o src/main.cpp src/circle.cpp src/rectangle.cpp src/window.cpp src/player.cpp src/vector.cpp src/ball.cpp src/game.cpp src/text.cpp $(LIBS)

# remove o arquivo executável gerado
clean:
	rm -f main
