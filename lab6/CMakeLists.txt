add_executable(main main.cpp)

add_library(lab6_lib src/field.cpp src/visitor.cpp)

target_include_directories(lab6_lib PUBLIC include)

target_link_libraries(main PUBLIC lab6_lib)

add_subdirectory(test)
