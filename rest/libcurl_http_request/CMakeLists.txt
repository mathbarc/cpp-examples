find_package(CURL)
find_package(CURLPP)

add_executable(request_curl request_curl.cpp)
target_link_libraries(request_curl curl)

add_executable(request_curlpp request_curlpp.cpp)
target_link_libraries(request_curlpp curlpp)
