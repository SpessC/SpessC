cmake_minimum_required(VERSION 3.10)

project(SpessC VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRC_FILES
	"engine/source/*/*.c"
)

add_executable(SpessC ${SRC_FILES})


include_directories(engine/includes)

include_directories(raylib)
link_directories(raylib)

find_library(raylib raylib "raylib/")

target_link_libraries(SpessC ${raylib})
target_link_libraries(SpessC m dl pthread)


set(CMAKE_C_FLAGS "-g -rdynamic -fsanitize=address")

set(CMAKE_C_FLAGS "-Werror -Wall -Wextra -pedantic -Wwrite-strings")

