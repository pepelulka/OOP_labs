add_executable(main main.cpp)

add_library(lab7_lib src/field.cpp src/visitor.cpp)

target_include_directories(lab7_lib PUBLIC include)

target_link_libraries(main PUBLIC lab7_lib)

add_subdirectory(test)
