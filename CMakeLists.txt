cmake_minimum_required(VERSION 3.10)

project(SpessC VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRC_FILES
	"engine/source/*/*.c"
)

add_executable(SpessC ${SRC_FILES})