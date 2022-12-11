cmake_minimum_required(VERSION 3.24)
project(TP03_PAA C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TP03_PAA
        comparacao.c
        comparacao.h
        leituraDeArquivo.c
        leituraDeArquivo.h
        main.c
        produtoCartesiano.c
        produtoCartesiano.h
        similaridade.c
        similaridade.h)

target_link_libraries(TP03_PAA PRIVATE m)
