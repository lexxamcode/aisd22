cmake_minimum_required(VERSION 3.2)

project(aisd2_2)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/libs/termcolor" "termcolor")

add_executable(project cli/cli.cpp functions/functions.h)
add_executable(setup cli/setup.cpp)
add_executable(mktable cli/mktable.cpp)
add_executable(ui ui/ui.cpp)

target_link_libraries(ui PRIVATE termcolor)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	target_compile_options(project PRIVATE /W4)
else()
	target_compile_options(project PRIVATE -Wall -Wextra -pedantic -Werror)
endif()