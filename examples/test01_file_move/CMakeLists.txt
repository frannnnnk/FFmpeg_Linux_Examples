
project(test01_file_move)

file(GLOB SRCS *.cpp)
add_executable(${PROJECT_NAME} ${SRCS})

include_directories(${PROJECT_NAME} ${FFmpeg_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${FFmpeg_LIBRARIES})