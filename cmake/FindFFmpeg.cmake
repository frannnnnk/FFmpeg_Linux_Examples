set(FFMPEG_BASE_DIR "/opt/homebrew/Cellar/ffmpeg/6.1.1_1/")

unset(INCLUDE_DIR CACHE)
find_path(INCLUDE_DIR
    NAMES libavcodec/codec.h libavformat/avformat.h
    HINTS ${FFMPEG_BASE_DIR}
    PATH_SUFFIXES include/
)
list(APPEND FFmpeg_INCLUDE_DIR ${INCLUDE_DIR})

set(FFmpeg_Libs avcodec avdevice avfilter avformat avutil postproc swresample swscale)
foreach(FFmpeg_lib ${FFmpeg_Libs})
    unset(LIBS CACHE)
    find_library(LIBS
        NAMES ${FFmpeg_lib}
        HINTS HINTS ${FFMPEG_BASE_DIR}
        PATH_SUFFIXES lib/
    )
list(APPEND FFmpeg_LIBRARIES ${LIBS})
    
endforeach(FFmpeg_lib ${})

if (FFmpeg_INCLUDE_DIR AND FFmpeg_LIBRARIES)
    set(FFmpeg_FOUND TRUE)
    message(STATUS ">>> found FFmpeg, include dir = ${FFmpeg_INCLUDE_DIR}")
    message(STATUS ">>> found FFmpeg, lib dir = ${FFmpeg_LIBRARIES}")
endif(FFmpeg_INCLUDE_DIR AND FFmpeg_LIBRARIES)