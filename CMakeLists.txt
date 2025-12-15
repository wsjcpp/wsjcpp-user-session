cmake_minimum_required(VERSION 3.0)

project(wsjcpp-user-session C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-user-session_SOURCE_DIR})

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_user_session.cpp")

#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (wsjcpp-user-session ${WSJCPP_SOURCES})

target_link_libraries(wsjcpp-user-session ${WSJCPP_LIBRARIES})

install(
    TARGETS
        wsjcpp-user-session
    RUNTIME DESTINATION
        /usr/bin
)

