extern "C" {
    #include <libavutil/log.h>
    #include <libavformat/avformat.h>
}
#include "log.h"

int main(int argc,char* argv[])
{   
    set_log_callback();
    av_log_set_level(AV_LOG_DEBUG); //设置日志级别
    av_log(NULL, AV_LOG_INFO, "Hello, FFmpeg!");
    return 0;
}