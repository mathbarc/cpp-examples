find_package(CURL)

add_executable(request request.cpp)
target_link_libraries(request curl)
