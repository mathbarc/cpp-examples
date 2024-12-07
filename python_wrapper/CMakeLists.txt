add_library(util util.hpp util.cpp)
find_package(Python REQUIRED)
find_package(SWIG 4.0 COMPONENTS python)

if(SWIG_FOUND)
    include(UseSWIG)
    FIND_PACKAGE(PythonLibs)
    INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH}
                        ${CMAKE_CURRENT_SOURCE_DIR})
    set_property(SOURCE util.i PROPERTY CPLUSPLUS ON)
    swig_add_library(pyutil LANGUAGE python SOURCES util.i)
    target_link_libraries(pyutil util)
endif()
