cmake_minimum_required(VERSION 3.15)

project(project_euler)

set(CMAKE_CXX_STANDARD 17)

set(COMPILE_WARNING_AS_ERROR ON)

function(add_solver EXE_NAME)
    message(STATUS "Create exe(${EXE_NAME}) with src(${ARGN})")

    if(NOT DEFINED EXE_NAME)
        message(FATAL_ERROR "EXE_NAME is not defined")
    else()
        list(LENGTH ARGN length)
        if(length LESS 1)
            message(FATAL_ERROR "src files are not defined")
        endif()
    endif()

    add_executable(${EXE_NAME} ${ARGN})
endfunction()

add_subdirectory(problem34)
add_subdirectory(problem35)
add_subdirectory(problem52)
