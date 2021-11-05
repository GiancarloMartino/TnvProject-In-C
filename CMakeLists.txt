cmake_minimum_required(VERSION 3.17)
project(TnvProject C)

set(CMAKE_C_STANDARD 90)

add_executable(TnvProject main.c libreria_primaria.c libreria_primaria.h AzioneConfronti.c AzioneConfronti.h stampe.c stampe.h controlli.c controlli.h)