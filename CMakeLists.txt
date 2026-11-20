cmake_minimum_required(VERSION 3.16)
project(tp2 LANGUAGES CXX)

# ---------------------------------------------------------------
#  CMake multiplateforme : Windows (MSYS2/MinGW), macOS, Linux
# ---------------------------------------------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # pour l'autocomplétion de VS Code
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Tous les .cpp du dossier (les nouveaux fichiers sont pris en compte automatiquement)
file(GLOB SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/*.cpp)
add_executable(tp2 ${SOURCES})

if(MSVC)
    # Compilateur Microsoft (Visual Studio)
    target_compile_options(tp2 PRIVATE /W4)
else()
    # GCC (Windows MinGW, Linux) et Clang (macOS)
    target_compile_options(tp2 PRIVATE -Wall -Wextra)
    # lit_ecrit.cpp utilise toascii() sans inclure <cctype> :
    # on l'inclut d'office pour que tous les compilateurs le trouvent
    target_compile_options(tp2 PRIVATE -include cctype)
endif()

if(MINGW)
    # Windows : exécutable autonome, évite les conflits de DLL
    # avec d'autres outils présents dans le PATH
    target_link_options(tp2 PRIVATE -static)
endif()
