cmake_minimum_required(VERSION 3.22.1)
project(Arvore_B)

# Adiciona os arquivos fonte
add_executable(main    
    main.c        
        biblioteca/lista/lista_dupla.c
        biblioteca/arvore_b/arvore.c
)

target_link_libraries(main m)
target_compile_options(main PRIVATE -Wall -Wextra -g)