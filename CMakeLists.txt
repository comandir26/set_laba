cmake_minimum_required(VERSION 3.11)

project(set_template CXX)

set(CMAKE_CXX_STANDARD 23)

# ����������� ��������� ��� ����������� Visual Studio
if(MSVC)
    # ���������� ����������� �������� ��� ������������ ���������
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # �������� ������� ������� ��������������
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# ��������� ����������
add_library(set_template SHARED
    "include/my_set/my_set.h"
    "src/my_set.cc"
)

target_include_directories(set_template PUBLIC "include")

#����������� main
add_executable(main "src/main.cc")

target_link_libraries(main set_template)