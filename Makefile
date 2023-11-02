CXX = g++   #compilador c++
CXXFLAGS = -Wall -I/usr/include/SDL # flags de compilação, -Wall (habilitar warnings), 
# -I/usr/include/SDL2 especifica onde encontrar os cabeçalhos da SDL2.
LIBS = -lSDL2 # Bibliotecas 
EXECUTABLES = main # oq vai ser chamado(?)

# regra: dependências
#    comandos a serem executados para compilar o código
all: $(EXECUTABLES)

main: main.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp $(LIBS)

# remove o arquivo executável gerado
clean:
	rm -f main

# COMO RODAR UM ARQ
# ./nome_arq

# ERROS:
# "faltando o separador" em um arquivo Makefile ocorre quando a formatação do arquivo não está correta.

# COMO SABER AS FLAGS
# pkg-config sdl2 --cflags
# pkg-config --list-all
#  COMO SABER AS LIBS
# pkg-config sdl2 --libs